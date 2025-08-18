// ===================================================================
// PIPELINE BEST PRACTICES
// ===================================================================
// The following guidelines should be followed for all stages in this pipeline:
//
// 1. REPOSITORY HANDLING:
//    - Always create and operate on a copy of the repository when performing any processing
//    - Example: Copy to docker_workarea/[stage_name]/ and operate on that copy
//    - This prevents cascading effects between stages and ensures isolation
//
// 2. ARTIFACT MANAGEMENT:
//    - Ensure all stage outputs and artifacts are copied to the designated artifacts directory [ARTIFACTS_PATH/stage_name]
//    - Use consistent paths and naming conventions for all artifacts
//    - Document the purpose and content of each artifact
//
// 3. ERROR HANDLING:
//    - Include appropriate error handling and logging in each stage
//    - Capture and report meaningful error messages
//    - Consider retry mechanisms for transient failures
//
// 4. STAGE DEPENDENCIES:
//    - Document dependencies between stages clearly
//    - Use when/beforeAgent conditions to enforce dependencies
//    - Consider using stash/unstash for passing data between stages
//
// 5. CLEANUP:
//    - Provide cleanup mechanisms for temporary files and resources
//    - Use post sections to ensure cleanup happens even on failure
//    - Remove temporary copies of repositories after use
//
// 6. NAMING CONVENTIONS:
//    - Use consistent naming conventions for stage inputs/outputs
//    - Follow pattern: [stage_name]_[artifact_type]_[version]
//    - Document naming conventions in comments
//
// 7. INPUT VALIDATION:
//    - Implement proper validation of inputs before stage execution
//    - Check for required environment variables and parameters
//    - Fail fast if prerequisites are not met
//
// ===================================================================
// GLOBAL VARIABLES
// ===================================================================

// Build Status Information
def BUILD_STATUS = "UNKNOWN"  // Track build status across stages

// Build Trigger Information
// Variables related to how the build was triggered and PR details
// ===================================================================
def TRIGGER_SOURCE = "UNKNOWN"  // Source of the build trigger (PR, NIGHTLY, MANUAL)
def PR_NUMBER = ""              // Pull request number if triggered by PR
def PR_SOURCE_BRANCH = ""       // Source branch of the PR
def PR_TARGET_BRANCH = ""       // Target branch of the PR
def PR_URL = ""                 // URL of the PR
def SHOULD_STORE_ARTIFACTS_IN_NAS = false  // Whether to store artifacts in NAS
def SHOULD_RUN_TESTS = false    // Whether to run tests
def SHOULD_GENERATE_DOCS = false // Whether to generate documentation
def NAS_UPLOAD_SUCCESS = false   // Whether NAS upload was successful
def NAS_PATH = ""               // Path on NAS server where artifacts will be stored
def NAS_WEB_PATH = ""           // Web accessible URL path for artifacts on NAS server
def EMAIL_RECIPIENT = ""        // Email recipient for notifications

// Docker Configuration
// Variables related to Docker container and image settings
// ===================================================================
def DOCKER_IMAGE = null                             // Will hold the Docker image object
def DOCKER_IMAGE_NAME = "c29x_mcal_pipeline"        // Docker image name
def DOCKER_CONTAINER_NAME = "c29x_mcal_pipeline_container"  // Docker container name

// NAS Server Configuration
// Variables related to NAS server for artifact storage
// ===================================================================
def NAS_USER = "epswbld"                            // NAS server username
def NAS_ADDRESS = "epswnas.itg.ti.com"              // NAS server hostname or IP address
def NAS_BASE_PATH = "/data/mcal_asm_cicd/mcal_c29x_pipeline" // Base path on NAS server

// Test Server Configuration
// Variables related to test server and job URLs
// ===================================================================
def TEST_SERVER_BASE_URL = "https://jenkins-proc.itg.ti.com"  // Base URL for the test server
def TEST_JOB_PATH = "view/MCAL/job/mcal_f29h85_evm_ccs_test"  // Path to the specific test job
def TEST_JOB_URL = "${TEST_SERVER_BASE_URL}/${TEST_JOB_PATH}"  // Full URL to the test job
def TEST_JOB_PARAMS_URL = "${TEST_JOB_URL}/buildWithParameters"  // URL for triggering the test job with parameters

// Bitbucket Insights Configuration
// Variables related to Bitbucket Insights for PR reporting
// ===================================================================
def BASE_INSIGHTS = "https://bitbucket.itg.ti.com/rest/insights/1.0"  // Base URL for Bitbucket Insights API
def BB_PROJECT = "PLATSWMCAL"                       // Bitbucket project name
def BB_REPO_NAME = "C29x_mcal"                      // Bitbucket repository name
def REPORT_KEY = ""                    // Key for the PR Bot report
def REPORT_URL = ""                                 // Will be set in Detect Trigger Source stage

pipeline {
    // Run on agents with label "full" or "partial"
    agent {
        label 'full||partial'
    }
    
    // Define parameters for the pipeline
    parameters {
        string(
            name: 'MCAL_SCRIPTS_BRANCH',
            defaultValue: 'feature/MCAL-22095-implement-pipeline',
            description: 'Branch to checkout for mcal_scripts repository'
        )
        booleanParam(
            name: 'FORCE_DELETE_DOCKER_IMAGE',
            defaultValue: false,
            description: 'Force delete the Docker image before building a new one'
        )
        booleanParam(
            name: 'QUICK_BUILD',
            defaultValue: false,
            description: 'Enable quick build mode (builds all examples but only one configuration per project in CCS)'
        )
        booleanParam(
            name: 'STORE_ARTIFACTS_IN_NAS',
            defaultValue: false,
            description: 'Push artifacts to NAS server (default: false for Manual, true for PR and Nightly)'
        )
        booleanParam(
            name: 'RUN_TESTS',
            defaultValue: false,
            description: 'Run Tests for manual triggers'
        )
        string(
            name: 'JIRA_FILTER',
            defaultValue: 'project = MCAL AND Platform = F29H85x-evm',
            description: 'JIRA filter for test cases to run'
        )
        booleanParam(
            name: 'GENERATE_DOCS',
            defaultValue: false,
            description: 'Generate User Guide for manual triggers'
        )
    }
    
    // Configure options for the pipeline
    options {
        // Add timestamps to console output
        timestamps()
        // Discard old builds, keeping only the last 30
        buildDiscarder(logRotator(numToKeepStr: '30'))
        // Timeout if the pipeline takes more than 2 hours
        timeout(time: 2, unit: 'HOURS')
        // Skip the default checkout to prevent double cloning
        skipDefaultCheckout(true)
    }
    
    // Configure triggers for the pipeline
    triggers {
        // Schedule nightly builds at 00:00 IST only on 'next' branch
        // Jenkins server appears to be in US Eastern Time (ET)
        cron(env.BRANCH_NAME == 'next' ? '30 13 * * *' : '')
    }
    
    // Define environment variables
    environment {
        C29X_MCAL_PATH = "${WORKSPACE}/git_repo/c29x_mcal"
        MCAL_SCRIPTS_PATH = "${WORKSPACE}/git_repo/mcal_scripts"
        
        // Capture Jenkins user information for Docker container
        JENKINS_USER_NAME = "${sh(script:'id -un', returnStdout: true).trim()}"
        JENKINS_USER_ID = "${sh(script:'id -u', returnStdout: true).trim()}"
        JENKINS_GROUP_ID = "${sh(script:'id -g', returnStdout: true).trim()}"
    }
    
    stages {
        stage('Checkout') {
            steps {
                // Create git_repo directory
                sh "mkdir -p git_repo"
                
                dir('git_repo') {
                    // Clone the current repository into c29x_mcal subdirectory
                    dir('c29x_mcal') {
                        checkout scm
                    }
                    
                    // Fast clone the mcal_scripts repository without full history
                    // Use sparse checkout to exclude large directories for improved clone time
                    dir('mcal_scripts') {
                        checkout([
                            $class: 'GitSCM',
                            branches: [[name: "*/${params.MCAL_SCRIPTS_BRANCH}"]],
                            extensions: [
                                [
                                    $class: 'CloneOption',
                                    shallow: true,
                                    depth: 1,
                                    timeout: 30,
                                    noTags: true
                                ],
                                [
                                    $class: 'SparseCheckoutPaths',
                                    sparseCheckoutPaths: [
                                        // Only include specific required paths - without leading slashes
                                        // Include jenkins directory and all its contents
                                        [path: 'jenkins/**'],
                                        // Include vector directory and all its contents
                                        [path: 'tools/vector/**']
                                    ]
                                ]
                            ],
                            userRemoteConfigs: [[
                                url: 'ssh://git@bitbucket.itg.ti.com/platswmcal/mcal_scripts.git'
                            ]]
                        ])
                    }
                }
                
                echo "Repositories cloned with the requested folder structure"
            }
        }
        
        // Detect the trigger source after checkout
        stage('Detect Trigger Source') {
            steps {
                script {
                    // Get build causes
                    def causes = currentBuild.getBuildCauses()
                    echo "Build causes: ${causes}"
                    
                    // Detect PR trigger - check build causes
                    if (causes.toString().contains("BranchEventCause")) {
                        TRIGGER_SOURCE = "PR"
                        PR_NUMBER = env.CHANGE_ID
                        PR_SOURCE_BRANCH = env.CHANGE_BRANCH
                        PR_TARGET_BRANCH = env.CHANGE_TARGET
                        PR_URL = env.CHANGE_URL
                        
                        // Enable storing artifacts in NAS for PR builds
                        SHOULD_STORE_ARTIFACTS_IN_NAS = true
                        
                        echo "Build triggered by PR #${PR_NUMBER}"
                        echo "Source branch: ${PR_SOURCE_BRANCH}"
                        echo "Target branch: ${PR_TARGET_BRANCH}"
                        echo "PR URL: ${PR_URL}"
                        echo "Enabled storing artifacts in NAS for PR build"
                    }
                    // Detect nightly build
                    else if ((causes.toString().contains("TimerTrigger") && (env.BRANCH_NAME == "next"))) {
                        TRIGGER_SOURCE = "NIGHTLY"
                        echo "Build triggered by nightly schedule on next branch"
                        echo "Branch: ${env.BRANCH_NAME ?: env.GIT_BRANCH}"
                        
                        // Enable tests, docs generation, and storing artifacts in NAS for nightly builds
                        SHOULD_RUN_TESTS = true
                        SHOULD_GENERATE_DOCS = true
                        SHOULD_STORE_ARTIFACTS_IN_NAS = true
                        echo "Enabled tests, docs generation, and storing artifacts in NAS for nightly build"
                    }
                    // Default to manual trigger
                    else {
                        TRIGGER_SOURCE = "MANUAL"
                        // For manual builds, use the parameter values
                        SHOULD_STORE_ARTIFACTS_IN_NAS = params.STORE_ARTIFACTS_IN_NAS
                        
                        // Ensure RUN_TESTS can only be true if STORE_ARTIFACTS_IN_NAS is also true
                        if (params.RUN_TESTS && !params.STORE_ARTIFACTS_IN_NAS) {
                            echo "WARNING: RUN_TESTS is set to true but STORE_ARTIFACTS_IN_NAS is false."
                            echo "Setting SHOULD_RUN_TESTS to false as tests require artifacts to be stored in NAS."
                            SHOULD_RUN_TESTS = false
                        } else {
                            SHOULD_RUN_TESTS = params.RUN_TESTS
                        }
                        
                        SHOULD_GENERATE_DOCS = params.GENERATE_DOCS
                        echo "Build triggered manually by user"
                        echo "Branch: ${env.BRANCH_NAME ?: env.GIT_BRANCH}"
                    }
                    
                    // Print summary
                    echo "TRIGGER_SOURCE set to: ${TRIGGER_SOURCE}"
                    
                    // Calculate NAS path once and store it for later use
                    def destinationPath = ""
                    if (TRIGGER_SOURCE == "PR") {
                        destinationPath = "${PR_NUMBER}/${env.BUILD_NUMBER}"
                    } else {
                        // For NIGHTLY and MANUAL triggers, use branch name
                        def branchName = env.BRANCH_NAME ?: env.GIT_BRANCH ?: "unknown"
                        // Remove any slashes from branch name to avoid path issues
                        branchName = branchName.replaceAll('/', '_')
                        destinationPath = "${branchName}/${env.BUILD_NUMBER}"
                    }
                    
                    // Store the full NAS path in a global variable for reuse
                    NAS_PATH = "${NAS_BASE_PATH}/${TRIGGER_SOURCE}/${destinationPath}"
                    // Calculate the web-accessible URL path (without /data prefix)
                    NAS_WEB_PATH = "http://${NAS_ADDRESS}${NAS_BASE_PATH.replace('/data', '')}/${TRIGGER_SOURCE}/${destinationPath}"
                    echo "NAS path calculated once: ${NAS_PATH}"
                    echo "NAS web path calculated once: ${NAS_WEB_PATH}"
                    
                    // Determine email recipient based on trigger source
                    echo "Determining email recipient based on trigger source: ${TRIGGER_SOURCE}"
                    
                    if (TRIGGER_SOURCE == "NIGHTLY") {
                        // For nightly builds, send to the team email
                        EMAIL_RECIPIENT = "asm_mcal@list.ti.com"
                        echo "Email recipient set to team email: ${EMAIL_RECIPIENT}"
                    } else if (TRIGGER_SOURCE == "MANUAL") {
                        // For manual builds, send to the person who triggered the build
                        EMAIL_RECIPIENT = "${currentBuild.getBuildCauses()[0].userId}@ti.com"
                        echo "Email recipient set to build trigger user: ${EMAIL_RECIPIENT}"
                    } else if (TRIGGER_SOURCE == "PR") {
                        // For PR builds, get the last committer's email using git log
                        dir('git_repo/c29x_mcal') {
                            EMAIL_RECIPIENT = sh(
                                script: "git log -1 --pretty=format:'%ae'",
                                returnStdout: true
                            ).trim()
                        }
                        echo "Email recipient set to PR author: ${EMAIL_RECIPIENT}"
                    }
                    
                    // Default recipient if we couldn't determine one or if the email is lcpdbld@list.ti.com
                    // The lcpdbld@list.ti.com check is added because git log sometimes returns this system account
                    // instead of the actual committer's email, which is not the intended recipient
                    if (!EMAIL_RECIPIENT || EMAIL_RECIPIENT.isEmpty() || EMAIL_RECIPIENT == "lcpdbld@list.ti.com") {
                        if (EMAIL_RECIPIENT == "lcpdbld@list.ti.com") {
                            echo "Detected system account email (lcpdbld@list.ti.com). Using default recipient instead."
                        }
                        EMAIL_RECIPIENT = "asm_mcal@list.ti.com"
                        echo "Using default email recipient: ${EMAIL_RECIPIENT}"
                    }
                    
                    // Append BUILD_NUMBER to DOCKER_CONTAINER_NAME
                    DOCKER_CONTAINER_NAME = "${DOCKER_CONTAINER_NAME}_${env.BUILD_NUMBER}"
                    DOCKER_CONTAINER_NAME = DOCKER_CONTAINER_NAME.replaceAll(/[^a-zA-Z0-9_.-]/, '_')
                    echo "Updated Docker container name: ${DOCKER_CONTAINER_NAME}"
                }
            }
        }
        
        stage('Docker Setup') {
            steps {
                // Create docker workarea directory in parallel to git_repo
                sh "mkdir -p docker_workarea"

                // Create docker artifacts directory in parallel to git_repo
                sh "mkdir -p artifacts"
                
                script {
                    // Check if Docker container already exists and remove it
                    echo "Checking for existing Docker container ${DOCKER_CONTAINER_NAME}..."
                    sh "docker rm -f ${DOCKER_CONTAINER_NAME} || true"
                    
                    // Force delete Docker image if requested
                    if (params.FORCE_DELETE_DOCKER_IMAGE) {
                        echo "Force deleting Docker image ${DOCKER_IMAGE_NAME}..."
                        sh "docker rmi -f ${DOCKER_IMAGE_NAME} || true"
                    }
                    
                    // Build the Docker image using Jenkins Docker plugin
                    echo "Building Docker image ${DOCKER_IMAGE_NAME}..."
                    // The context directory is where the Dockerfile is located
                    def dockerContext = "${MCAL_SCRIPTS_PATH}/jenkins/c29x_mcal"
                    // Build and store the image for later use
                    DOCKER_IMAGE = docker.build(DOCKER_IMAGE_NAME, "-f ${dockerContext}/Dockerfile --build-arg UID=${JENKINS_USER_ID} --build-arg GID=${JENKINS_GROUP_ID} --build-arg UNAME=${JENKINS_USER_NAME} ${dockerContext}")
                    
                    echo "Docker image ${DOCKER_IMAGE_NAME} built successfully"
                }
            }
        }
        
        // All stages that need to run in the Docker container
        stage('Docker Stages') {
            agent {
                docker {
                    image "${DOCKER_IMAGE_NAME}"
                    reuseNode true  // Run on the same node as the pipeline
                    // Mount volumes and set container name
                    args """
                        --name ${DOCKER_CONTAINER_NAME}
                        -v ${HOME}/.ssh:/home/${JENKINS_USER_NAME}/.ssh:ro
                    """
                }
            }
            
            // Set environment variables for paths inside the container
            environment {
                C29X_MCAL_PATH = "${WORKSPACE}/git_repo/c29x_mcal"
                MCAL_SCRIPTS_PATH = "${WORKSPACE}/git_repo/mcal_scripts"
                COMPILER_PATH = "/home/${JENKINS_USER_NAME}/tools/compiler"
                CCS_PATH = "/home/${JENKINS_USER_NAME}/tools/ccs/ccs"
                ARTIFACTS_PATH = "${WORKSPACE}/artifacts"
            }
                        
            stages {
                stage('Build and Compliance Checks') {
                    parallel {
                        stage('PR Bot') {
                            when {
                                expression { TRIGGER_SOURCE == "PR" }
                            }
                            steps {
                                script {
                                    echo "Starting PR Bot checks..."
                                    
                                    // Create pr_bot directory inside docker_workarea for this stage
                                    sh "mkdir -p ${WORKSPACE}/docker_workarea/pr_bot"
                                    
                                    // Copy the c29x_mcal repo to docker_workarea/pr_bot to prevent cascading effects
                                    echo "Copying c29x_mcal repo to docker_workarea/pr_bot/"
                                    sh "cp -rf ${C29X_MCAL_PATH}/. ${WORKSPACE}/docker_workarea/pr_bot/ || true"
                                    
                                    // Define the path to the copied repo
                                    def COPIED_MCAL_PATH = "${WORKSPACE}/docker_workarea/pr_bot"
                                    // Fetch the source branch and get its latest commit
                                    def COMMIT_ID = sh(script: """
                                        cd ${COPIED_MCAL_PATH} &&
                                        git fetch origin ${PR_SOURCE_BRANCH} &&
                                        git rev-parse FETCH_HEAD
                                    """, returnStdout: true).trim()
                                    echo "Using source branch commit ID: ${COMMIT_ID}"
                                    REPORT_KEY = "git-checks"
                                    // Set REPORT_URL for Bitbucket Insights
                                    REPORT_URL = "${BASE_INSIGHTS}/projects/${BB_PROJECT}/repos/${BB_REPO_NAME}/commits/${COMMIT_ID}/reports/${REPORT_KEY}"
                                    echo "Set REPORT_URL: ${REPORT_URL}"
                                    
                                    // Make the pr_bot.sh script executable
                                    sh "chmod +x ${MCAL_SCRIPTS_PATH}/jenkins/c29x_mcal/pr_bot/pr_bot.sh"
                                    
                                    // Call the pr_bot.sh script with the necessary parameters
                                    def prBotResult = sh(
                                        script: """
                                            cd ${COPIED_MCAL_PATH} && \
                                            SOURCE_BRANCH=${PR_SOURCE_BRANCH} \
                                            TARGET_BRANCH=${PR_TARGET_BRANCH} \
                                            BB_REPO=${COPIED_MCAL_PATH} \
                                            REPORT_URL="${REPORT_URL}" \
                                            REPORT_KEY="${REPORT_KEY}" \
                                            ${MCAL_SCRIPTS_PATH}/jenkins/c29x_mcal/pr_bot/pr_bot.sh
                                        """,
                                        returnStatus: true
                                    )
                                    
                                    // Check the return code from the pr_bot script
                                    if (prBotResult == 0) {
                                        echo "PR Bot checks completed successfully"
                                    } else {
                                        error("PR Bot checks failed with exit code: ${prBotResult}")
                                    }
                                }
                            }
                            post {
                                always {
                                    // Clean up the copied repo after PR Bot checks are complete
                                    echo "Cleaning up copied repository in docker_workarea/pr_bot"
                                    sh "rm -rf ${WORKSPACE}/docker_workarea/pr_bot/*"
                                }
                            }
                        }
                        
                        stage('Code Checker') {
                            steps {
                                echo "Code Checker stage - implementation pending"
                            }
                        }

                        stage('Lint Check') {
                            steps {
                                script {
                                    echo "Starting Lint Checks"

                                    // Create lint directory inside docker_workarea for this stage
                                    sh "mkdir -p ${WORKSPACE}/docker_workarea/lint"
                                    
                                    // Create artifacts directory for lint output
                                    sh "mkdir -p ${ARTIFACTS_PATH}/lint"
                                    
                                    // Copy the c29x_mcal repo to docker_workarea/lint/ to prevent cascading effects
                                    echo "Copying c29x_mcal repo to docker_workarea/lint/"
                                    // Use cp with -f to force copy and continue even if there are permission errors
                                    sh "cp -rf ${C29X_MCAL_PATH}/. ${WORKSPACE}/docker_workarea/lint/ || true"
                                    
                                    // Define the path to the copied repo
                                    def COPIED_MCAL_PATH = "${WORKSPACE}/docker_workarea/lint"
                                    
                                    // Make the lint_check.py script executable
                                    sh "chmod +x ${MCAL_SCRIPTS_PATH}/jenkins/c29x_mcal/lint_check/lint_check.py"
                                    
                                    // Prepare the lint command with PR argument if needed
                                    def lintCommand = "python3 ${MCAL_SCRIPTS_PATH}/jenkins/c29x_mcal/lint_check/lint_check.py"
                                    
                                    // Add PR argument if this is a PR build
                                    if (TRIGGER_SOURCE == "PR") {
                                        lintCommand += " --pr"
                                        
                                        // Fetch the source branch and get its latest commit
                                        def COMMIT_ID = sh(script: """
                                            cd ${COPIED_MCAL_PATH} &&
                                            git fetch origin ${PR_SOURCE_BRANCH} &&
                                            git rev-parse FETCH_HEAD
                                        """, returnStdout: true).trim()
                                        echo "Using source branch commit ID: ${COMMIT_ID}"
                                        REPORT_KEY = "lint-checks"
                                        // Set REPORT_URL for Bitbucket Insights
                                        REPORT_URL = "${BASE_INSIGHTS}/projects/${BB_PROJECT}/repos/${BB_REPO_NAME}/commits/${COMMIT_ID}/reports/${REPORT_KEY}"
                                        echo "Set REPORT_URL: ${REPORT_URL}"
                                        
                                        // Add REPORT_KEY, REPORT_URL, and NAS_WEB_PATH arguments
                                        lintCommand += " --report-key ${REPORT_KEY} --report-url ${REPORT_URL} --nas-web-path ${NAS_WEB_PATH}/lint"
                                    }
                                    
                                    // Add the required arguments
                                    lintCommand += " ${COPIED_MCAL_PATH} ${COMPILER_PATH} ${ARTIFACTS_PATH}/lint"
                                    
                                    echo "Running lint check command: ${lintCommand}"
                                    
                                    // Call the lint_check.py script with clang-format in PATH
                                    def lintResult = sh(
                                        script: """
                                            # Run the lint command
                                            ${lintCommand}
                                        """,
                                        returnStatus: true
                                    )
                                    
                                    // Check the return code from the lint script
                                    if (lintResult == 0) {
                                        echo "Lint checks completed successfully"
                                    } else {
                                        echo "WARNING: Lint checks failed with exit code: ${lintResult}"
                                        echo "Continuing pipeline execution despite lint failures"
                                    }
                                }
                            }
                            post {
                                always {
                                    // Clean up the copied repo after lint checks are complete
                                    echo "Cleaning up copied repository in docker_workarea/lint"
                                    sh "rm -rf ${WORKSPACE}/docker_workarea/lint/*"
                                }
                            }
                        }
                        
                        stage('Build') {
                            when {
                                // Always run the Build stage regardless of previous stage results
                                expression { return true }
                            }
                            steps {
                                script {
                                    echo "Starting build process..."
                                    
                                    // Create build directory inside docker_workarea for this stage
                                    sh "mkdir -p ${WORKSPACE}/docker_workarea/build"
                                    
                                    // Copy the c29x_mcal repo to docker_workarea/build/ to prevent cascading effects
                                    echo "Copying c29x_mcal repo to docker_workarea/build/"
                                    // Use cp with -f to force copy and continue even if there are permission errors
                                    sh "cp -rf ${C29X_MCAL_PATH}/. ${WORKSPACE}/docker_workarea/build/ || true"
                                    
                                    // Define the path to the copied repo
                                    def COPIED_MCAL_PATH = "${WORKSPACE}/docker_workarea/build"
                                    
                                    // Determine if quick build should be used
                                    def useQuickBuild = false
                                    if (TRIGGER_SOURCE == "PR") {
                                        // Use quick build for PR builds
                                        useQuickBuild = true
                                        echo "Using quick build mode for PR build (builds all examples but only one configuration per project)"
                                    } else if (TRIGGER_SOURCE == "MANUAL" && params.QUICK_BUILD) {
                                        // Use quick build for manual builds if parameter is selected
                                        useQuickBuild = true
                                        echo "Using quick build mode for manual build (builds all examples but only one configuration per project)"
                                    }
                                    
                                    // Prepare the build command with quick build flag if needed
                                    def buildCommand = "python3 ${MCAL_SCRIPTS_PATH}/jenkins/c29x_mcal/build/build.py ${COMPILER_PATH} ${CCS_PATH} ${COPIED_MCAL_PATH} ${ARTIFACTS_PATH}/build"
                                    if (useQuickBuild) {
                                        buildCommand += " --quick-build"
                                    }
                                    
                                    // Call the build.py script with the copied repo path and artifacts path, then capture the return code
                                    def buildResult = sh(
                                        script: buildCommand,
                                        returnStatus: true
                                    )
                                    
                                    // Check the return code from the build script
                                    if (buildResult == 0) {
                                        echo "Build completed successfully"
                                        BUILD_STATUS = 'SUCCESS'
                                    } else {
                                        BUILD_STATUS = 'FAILURE'
                                        error("Build failed with exit code: ${buildResult}")
                                    }
                                }
                            }
                            post {
                                always {
                                    // Clean up the copied repo after build is complete
                                    echo "Cleaning up copied repository in docker_workarea/build"
                                    sh "rm -rf ${WORKSPACE}/docker_workarea/build/*"
                                }
                            }
                        }
                    }
                }

                stage('Post Build Tasks') {
                    when {
                        expression { BUILD_STATUS == 'SUCCESS' }
                    }
                    parallel {
                        stage('Klockwork') {
                            steps {
                                echo "Klockwork stage - implementation pending"
                            }
                        }

                        stage('User Guide') {
                            when {
                                expression {
                                    SHOULD_GENERATE_DOCS
                                }
                            }
                            steps {
                                echo "User Guide generation stage - implementation pending"
                            }
                        }
                    }
                }
            }
        }
        
        // NAS Upload stage - uploads artifacts to NAS server
        stage('NAS Upload') {
            when {
                expression { params.STORE_ARTIFACTS_IN_NAS || SHOULD_STORE_ARTIFACTS_IN_NAS }
            }
            steps {
                script {
                    echo 'Pushing artifacts to NAS server...'
                    try {
                        // Copy pipeline log to artifacts directory
                        echo "Copying pipeline log to artifacts directory..."
                        sh "mkdir -p ${WORKSPACE}/artifacts/logs"
                        sh "cp \${JENKINS_HOME}/jobs/\${JOB_NAME}/builds/\${BUILD_NUMBER}/log ${WORKSPACE}/artifacts/logs/pipeline.log || echo 'Warning: Could not copy pipeline log'"
                        
                        // Use the pre-calculated NAS path
                        echo "Using pre-calculated NAS path: ${NAS_PATH}"
                        
                        // Create directory on NAS server if it doesn't exist
                        sh """
                            ssh -o StrictHostKeyChecking=no ${NAS_USER}@${NAS_ADDRESS} "mkdir -p ${NAS_PATH}"
                        """
                        
                        // Push artifacts to NAS server using rsync
                        def rsyncResult = sh(
                            script: """
                                rsync --rsync-path=/usr/bin/rsync -e "ssh -o StrictHostKeyChecking=no" -Wa --inplace \
                                "artifacts/" \
                                ${NAS_USER}@${NAS_ADDRESS}:${NAS_PATH}
                            """,
                            returnStatus: true
                        )
                        
                        if (rsyncResult == 0) {
                            echo "Artifacts successfully pushed to NAS server at ${NAS_PATH}"
                            echo "Artifacts are web-accessible at ${NAS_WEB_PATH}"
                            // Set a flag to indicate NAS upload was successful
                            NAS_UPLOAD_SUCCESS = true
                        } else {
                            echo "WARNING: Failed to push artifacts to NAS server (exit code: ${rsyncResult})"
                            NAS_UPLOAD_SUCCESS = false
                            error "Failed to push artifacts to NAS server"
                        }
                    } catch (Exception e) {
                        echo "ERROR: Failed to push artifacts to NAS server: ${e.message}"
                        NAS_UPLOAD_SUCCESS = false
                        error "Exception occurred while pushing artifacts to NAS server: ${e.message}"
                    }
                }
            }
        }
        
        // Test stage - runs after artifacts are successfully uploaded to NAS
        // This stage depends on the NAS upload success because it needs to access the artifacts from the NAS path
        stage('Trigger Test Job') {
            when {
                expression { BUILD_STATUS == 'SUCCESS' && SHOULD_RUN_TESTS && NAS_UPLOAD_SUCCESS }
            }
            steps {
                script {
                    echo "Starting Test stage - triggering remote Jenkins job"
                    
                    // Use the pre-calculated NAS path
                    echo "Using pre-calculated NAS path for test job: ${NAS_PATH}"
                    
                    // Use the pre-defined URL for the remote Jenkins job
                    echo "Using test job parameters URL: ${TEST_JOB_PARAMS_URL}"
                    
                    // Determine the TEST_LABEL based on trigger type
                    def testLabel = ""
                    if (TRIGGER_SOURCE == "NIGHTLY") {
                        testLabel = "NIGHTLY"
                    } else if (TRIGGER_SOURCE == "MANUAL") {
                        testLabel = "DEV"
                    } else {
                        testLabel = "CICD"  // Default for PR builds and any other trigger types
                    }
                    
                    // Create a simple cause and a detailed description
                    def simpleCause = "MCAL C29x ${TRIGGER_SOURCE} Build #${env.BUILD_NUMBER}"
                    
                    def detailedDescription = "MCAL C29x ${TRIGGER_SOURCE} Build #${env.BUILD_NUMBER} - " +
                        (TRIGGER_SOURCE == "PR" ? "PR #${PR_NUMBER} from ${PR_SOURCE_BRANCH} to ${PR_TARGET_BRANCH}" :
                        "Branch: ${env.BRANCH_NAME ?: env.GIT_BRANCH ?: 'unknown'}") +
                        " - Triggered at ${new Date().format('yyyy-MM-dd HH:mm:ss')}"
                    
                    // Construct the query parameters
                    def queryParams = [
                        "token=MCAL",
                        "cause=${URLEncoder.encode(simpleCause, "UTF-8")}",
                        "BUILD_DESCRIPTION=${URLEncoder.encode(detailedDescription, "UTF-8")}",
                        "RTOS_BINS=${URLEncoder.encode("${NAS_WEB_PATH}/build/mcal_f29h85x_0x_0x_0x.tar.gz", "UTF-8")}",
                        "REPO_REVISION=${URLEncoder.encode("${NAS_WEB_PATH}/build/repo-revs.txt", "UTF-8")}",
                        "BINARY_TYPE=OUT",
                        "TEST_LABEL=${testLabel}",
                        "TEST_EMAIL_LIST=${URLEncoder.encode(EMAIL_RECIPIENT, "UTF-8")}",
                        "JIRA_FILTER=${URLEncoder.encode(params.JIRA_FILTER, "UTF-8")}"
                    ].join("&")
                    
                    // Full URL with parameters
                    def fullUrl = "${TEST_JOB_PARAMS_URL}?${queryParams}"
                    
                    echo "Triggering remote Jenkins job with URL: ${fullUrl}"
                    
                    // Use curl to trigger the remote job
                    def curlResult = sh(
                        script: "curl -s -o /dev/null -w '%{http_code}' '${fullUrl}'",
                        returnStdout: true
                    ).trim()
                    
                    // Check if the request was successful
                    if (curlResult == "201" || curlResult == "200") {
                        echo "Successfully triggered remote Jenkins job"
                        
                        // Print clickable links to the triggered job using the pre-defined URL
                        echo "Triggered test job can be accessed at: ${TEST_JOB_URL}"
                        
                        // Print a direct link to the job's console output (this will redirect to the latest build)
                        echo "View test job console output at: ${TEST_JOB_URL}/lastBuild/console"
                        
                        // Add a link to the Blue Ocean UI for a better user experience
                        echo "View test job in Blue Ocean UI: ${TEST_JOB_URL}/blue/organizations/jenkins/"
                    } else {
                        error "Failed to trigger remote Jenkins job. HTTP status code: ${curlResult}"
                    }
                }
            }
        }
        
        // NAS Cleanup stage - runs only during Nightly trigger to clean up old artifacts
        stage('NAS Cleanup') {
            when {
                expression { TRIGGER_SOURCE == "NIGHTLY" }
            }
            steps {
                script {
                    echo "Starting NAS cleanup process..."
                    
                    // Make the cleanup script executable
                    sh "chmod +x ${MCAL_SCRIPTS_PATH}/jenkins/c29x_mcal/NAS_Cleanup/nas_cleanup.sh"
                    
                    // Call the cleanup script with NAS server parameters
                    def cleanupResult = sh(
                        script: """
                            ${MCAL_SCRIPTS_PATH}/jenkins/c29x_mcal/NAS_Cleanup/nas_cleanup.sh \
                            --nas-user ${NAS_USER} \
                            --nas-address ${NAS_ADDRESS} \
                            --nas-base-path ${NAS_BASE_PATH}
                        """,
                        returnStatus: true
                    )
                    
                    // Check the return code from the cleanup script
                    if (cleanupResult == 0) {
                        echo "NAS cleanup completed successfully"
                    } else {
                        echo "WARNING: NAS cleanup encountered issues (exit code: ${cleanupResult})"
                        // Don't fail the build if cleanup fails
                    }
                }
            }
        }
    }
    
    // Error handling
    post {
        success {
            echo 'Pipeline executed successfully!'
        }
        failure {
            echo 'Pipeline execution failed!'
        }
        unstable {
            echo 'Pipeline execution was marked as unstable!'
        }
        always {
            echo 'Pipeline execution completed.'
            
            // Send email notification
            script {
                // Make the email notification script executable
                sh "chmod +x ${MCAL_SCRIPTS_PATH}/jenkins/c29x_mcal/email_notify/send_email.sh"
                
                // Use the email recipient determined in the "Detect Trigger Source" stage
                echo "Using email recipient determined earlier: ${EMAIL_RECIPIENT}"
                
                // Determine build status
                def buildStatus = currentBuild.result ?: 'SUCCESS'
                def statusMessage = buildStatus == 'SUCCESS' ? 'Successful' : buildStatus
                
                // Get branch name
                def branchName = env.BRANCH_NAME ?: env.GIT_BRANCH ?: "unknown"
                
                // Create email subject
                def subject = "C29x MCAL Pipeline [${statusMessage}]: ${TRIGGER_SOURCE} Build #${env.BUILD_NUMBER}"
                
                // Call the email notification script to get the HTML content
                def emailBody = sh(
                    script: """
                        ${MCAL_SCRIPTS_PATH}/jenkins/c29x_mcal/email_notify/send_email.sh \
                        "${statusMessage}" \
                        "${env.JOB_NAME}" \
                        "${env.BUILD_NUMBER}" \
                        "${env.BUILD_URL}pipeline-overview/" \
                        "${TRIGGER_SOURCE}" \
                        "${NAS_WEB_PATH}" \
                        "${NAS_UPLOAD_SUCCESS}" \
                        "${branchName}" \
                        "${PR_NUMBER}" \
                        "${PR_SOURCE_BRANCH}" \
                        "${PR_TARGET_BRANCH}"
                    """,
                    returnStdout: true
                ).trim()
                
                // Send email using Jenkins emailext
                emailext(
                    to: EMAIL_RECIPIENT,
                    subject: subject,
                    body: emailBody,
                    mimeType: 'text/html'
                )
                
                echo "Email notification sent to: ${EMAIL_RECIPIENT}"
            }
            
            // Remove the Docker container if it exists
            script {
                echo 'Removing Docker container if it exists...'
                sh "docker rm -f ${DOCKER_CONTAINER_NAME} || true"
                
                // Note: We intentionally keep the Docker image for future builds
                // This improves build times by reusing the cached image
                // The image can be forcibly rebuilt using the FORCE_DELETE_DOCKER_IMAGE parameter
            }
            
            cleanWs() // Clean up workspace when the build is done
        }
    }
}