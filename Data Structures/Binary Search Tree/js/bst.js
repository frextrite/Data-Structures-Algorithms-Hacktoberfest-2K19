module.exports = class BinarySearchTree {
  constructor(val) {
    this.val = val;
    //left and right trees should be null by default
    this.left = this.right = null;
  }

  insert(val) {
    //Insert will insert a value in the appropriate place in the tree.

    if (val < this.val && this.left === null) {
      //First we check if the value is less than the current tree value
      //if it is, and the left doesn't exist, we'll create a BST on the
      //left with this value.

      this.left = new BinarySearchTree(val);
    } else if (val < this.val) {
      //If the value is less than the current tree value, but this.left
      //exists then we should consider invoking the value using the
      //insert method on the left.
      this.left.insert(val);
    } else if (this.right === null) {
      //iIf the value isn't less than the current tree value, then it
      //must be greater than or equal to the tree value. In this case, if
      //the right BST doesn't exist, we create the BST at the right.
      this.right = new BinarySearchTree(val);
    } else {
      //Lastly if there is a right BST, we'll invoke the insert method
      //on the right BST
      this.right.insert(val);
    }
  }

  search(val) {
    //This method will search if the value exist in the BST.
    if (val === this.val) {
      //First we check if the tree value is equal to the value we return
      //true
      return true;
    } else if (val < this.val && this.left === null) {
      //Another case is if the value is less than the tree value, and
      //there doesn't exist a left node. In which case it's false
      return false;
    } else if (val < this.val) {
      //If there is a left tree, then we should search the left tree
      return this.left.search(val);
    } else if (this.right === null) {
      //If we got to this point, then the value is greater than the tree
      //value, we check if the right node doesn't exist we turn false.
      return false;
    } else {
      //If the right node exist, then we search through the right.
      return this.right.search(val);
    }
  }
};
