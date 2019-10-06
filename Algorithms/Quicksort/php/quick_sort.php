<?php

function quick_sort($array){
	$left = $right = array();
	if(count($array) < 2){
		return $array;
	}
	$pivot_key = key($array);
	$pivot = array_shift($array);
	foreach($array as $val){
		if($val <= $pivot){
			$left[] = $val;
		}elseif($val > $pivot){
			$right[] = $val;
		}
	}
	return array_merge(quick_sort($left),array($pivot_key=>$pivot),quick_sort($right));
}
 
$array = array(4, 3, 0, 8, -1, 5, 1);
echo 'Original array : '.implode(',',$array);
$sorted_array = quick_sort($array);
echo 'Sorted array : '.implode(',',$sorted_array);
