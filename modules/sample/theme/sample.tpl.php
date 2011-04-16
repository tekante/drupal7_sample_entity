<?php 
/**
 * available variables
 * $sample - sample entity
 * $content - build array
 */

hide($content['mech_name']);
?>
<h2><?php print($sample->mech_name); ?></h2>
<hr>

<?php print render($content); ?>
