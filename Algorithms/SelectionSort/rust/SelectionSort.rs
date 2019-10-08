fn selection_sort(array: &mut [i32]) {
    for i in 0..array.len() {
        let min_idx = array[i..].iter()
            .enumerate()
            .min_by_key(|&(_, v)| v)
            .map(|(i, _)| i)
            .unwrap_or(0);

        array.swap(i, min_idx + i);
    }
}


fn main() {

    let mut array = [ 5, 9, 7, 3, 1, 2, 6, 10, 8, 4];

    selection_sort(&mut array);
    println!("Sorted Array {:?}", array);
}

