<?php

/**
 * form for adding/editing an entity
 */
function sample_form($form, &$form_state, $sample, $op, $entity_type) {
  if ($sample->sid && $op != 'clone') {
    $form['sid'] = array(
      '#type' => 'hidden',
      '#default_value' => $sample->sid,
    );
    // entity revision patch looks to the revision property on an entity to determine whether 
    // to create a new revision, key the checkbox to make creating the entity from the form
    // state values convenient
    $form['revision'] = array(
      '#type' => 'checkbox',
      '#title' => t('New Revision'),
      '#description' => t('Create a new revision'),
    );
  }

  if ($sample->rev_id) {
    $form['rev_id'] = array(
      '#type' => 'hidden',
      '#default_value' => $sample->rev_id,
    );
  }

  $form['mech_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Machine Name'),
    '#description' => t('The machine name for this instance'),
    '#max_length' => 50,
    '#default_value' => $sample->mech_name,
  );

  $form['message'] = array(
    '#type' => 'textfield',
    '#title' => t('Message'),
    '#description' => t('Some data you care about saving'),
    '#max_length' => 50,
    '#default_value' => $sample->message,
  );

  field_attach_form('sample', $sample, $form, $form_state);
  $form['submit'] = array(
    '#type' => 'submit',
    '#default_value' => t('Save'),
  );
  return $form;
}

/**
 * validate callback for sample entity editing form
 */
function sample_form_validate($form, &$form_state) {
  if (!empty($form_state['values']['sid'])) {
    $sample = sample_load($form_state['values']['sid']);
  }
  else {
    $sample = entity_create('sample', array());
  }
  field_attach_form_validate('sample', $sample, $form, $form_state);
}

/**
 * the submit handler
 */
function sample_form_submit($form, &$form_state) {
  $sample = entity_create('sample', $form_state['values']);
  // entity_create always returns a "new" object, make adjustments for that
  if (isset($form_state['values']['sid']) && !empty($form_state['values']['sid'])) {
    unset($sample->is_new);
  }
  field_attach_submit('sample', $sample, $form, $form_state);
  $sample->save();
  $form_state['redirect'] = $sample->uri();
}

