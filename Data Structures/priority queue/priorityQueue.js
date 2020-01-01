(function (exports) {

  var MaxHeap = {	
    h: [],
		
    last: function () {
      return this.h.pop();
    },
		
    size: function () {
      return this.h.length;
    },

    push: function (e) {
      var i = this.size(),
      
      parent = Math.ceil(i / 2) - 1;
      this.h[i] = e;
      this.bubbleUp(i);
		},

    bubbleUp: function (i) {
      var parent;
      
      while (i > 0) {
        parent = Math.ceil(i / 2) - 1;
        if (this.h[parent] < this.h[i]) {
          this.swap(this.h, parent, i);
          i = parent;
        } else {
          return;
        }
      }
    },
    
    pop: function () {
      var head = this.h[0];
      
      this.h[0] = this.last();
      this.h.splice(this.size() - 1, 1);
      this.heapify(0);
      
      return head;
    },
    
    peek: function () {
      return this.h[0];
    },
    
    swap: function (a, i , j) {
      var tmp = a[i];
      
      a[i] = a[j];
      a[j] = tmp;
    },
    
    sinkDown:  function (i, a) {
      var left = 2 * i + 1,
          right = left + 1,
          largest = i,
          len = a.length;
      a = a || this.h;
      
      if (left < len && a[left] > a[largest]) {
        largest = left;
      }
      
      if (right < len && a[right] > a[largest]) {
        largest = right;
      }
      
      if (largest !== i) {
        this.swap(a, i, largest);
        this.sinkDown(largest, a);
      }
    },
    
    remove: function (e) {
      var i = -1,
          len = this.size(),
          parent;
      
      while (++i < len) {
        if (this.h[i] === e) {
          e = this.last();
          
          if (i !== len - 1) {
            this.h[i] = e;
            parent = this.h[Math.ceil(i / 2 - 1)];
            (parent > e)?  this.sinkDown(i) : this.bubbleUp(i);
          }
          
          return;
        }
      };
    },
    
    buildHeap: function (a) {
      var i = Math.floor(a.length / 2);
      
      while (i-- >= 0) {
        this.sinkDown(i, a);
      }
    },
    
    create: function (a) {
      var o = Object.create(this);
      
      if (a && (a instanceof Array)) {
        o.buildHeap(o.h = a);
      }
    
      return o;
    },
    
    toSortedArray: function () {
      ///TODO needs to implemented
      return false;
    }
  };
  
  exports.MaxHeap = MaxHeap;
}(this));
