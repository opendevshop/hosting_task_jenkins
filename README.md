Hosting Tasks: Jenkins Queue
============================

This module allows using Jenkins as a Hosting Task Runner.

Setup
-----

1. Get jenkins running.  The [Docker images are nice](https://hub.docker.com/_/jenkins/), or you can [install it natively](https://wiki.jenkins-ci.org/display/JENKINS/Installing+Jenkins+on+Ubuntu). 

2. Copy the jenkins config from this module to the jenkins home directory.
  
    ```
    $ cp -rf /var/aegir/devmaster-0.x/profiles/devshop/modules/contrib/hosting_task_jenkins/jenkins_home/* /var/jenkins_home
    ```

  Visit "Manage Jenkins" > "Reload config from disk" button for the changes to take effect. 
  
3. The default configuration includes an SSH target as an example. You must change this to your aegir server.  Visit "Manage Jenkins" > "Configure System" > "SSH Remote Hosts"
4. Add the ./jenkins_home/jenkins_id_rsa.pub file to your aegir server at /var/aegir/.ssh/authorized_keys.  *If you are using the aegir_ssh module, you will need to add this key to your hostmaster/devmaster account at My Account > Edit > SSH Keys.
4. In production, generate new SSH keys to replace jenkins_id_rsa and jenkins_id_rsa.pub
5. Create a build in Jenkins of "hosting-task" to ensure jenkins can connect and run the drush command.
5. Turn off hosting queue runner and supervisor so tasks don't run that way:

  ```
  $ drush @hostmaster dis hosting_queued
  $ sudo service supervisor stop
  ```
6. Download and enable this module:

  ```
  $ drush @hostmaster dl hosting_task_jenkins
  $ drush @hostmaster en hosting_task_jenkins
  $ cd path/to/sites/all/modules/hosting_task_jenkins
  $ composer install
  ```

7. Configure the module at admin/hosting/jenkins.  Add your Jenkins URL.
8. Trigger a task to be run in the hostmaster front-end.  Check Jenkins, it should be triggered in the front.

Jenkins will take up some memory, so it's recommended you use it on another server, or on a server with enough memory to go around.