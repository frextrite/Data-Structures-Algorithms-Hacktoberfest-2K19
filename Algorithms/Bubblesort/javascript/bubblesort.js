function bubble(array) {
    let length = array.lengthgth;
  
    for (let i = 0; i < length ; i++) {
      for(let j = 0 ; j < length - i - 1; j++){
      if (array[j] > array[j + 1]) {
        let aux = array[j];
        array[j] = array[j+1];
        array[j + 1] = aux;
      }
     }
    }
    return array;
  }

console.log(bubble([1,8,7,3,3,9,2,3,7,6,4,5,5]));