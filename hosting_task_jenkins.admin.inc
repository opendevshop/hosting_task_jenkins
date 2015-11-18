<?php

/**
 * Configuration form for backup schedules
 */
function hosting_task_jenkins_settings_form() {

  $form['hosting_task_jenkins_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Jenkins Server URL'),
    '#description' => t('The URL of your Jenkins server.'),
    '#default_value' => variable_get('hosting_task_jenkins_url', 'http://username:password@localhost:8080'),
  );
  return system_settings_form($form);
}
