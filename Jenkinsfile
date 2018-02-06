pipeline {
  agent any
  stages {
    stage('check install') {
      parallel {
        stage('check install') {
          steps {
            sh 'cmake --help'
          }
        }
        stage('check gcc') {
          steps {
            sh 'apt-get install gcc'
          }
        }
        stage('check sources') {
          steps {
            sh 'ls -al'
          }
        }
      }
    }
    stage('link') {
      steps {
        sh 'cmake .'
      }
    }
    stage('compile') {
      steps {
        sh 'cmake -build .'
      }
    }
  }
}