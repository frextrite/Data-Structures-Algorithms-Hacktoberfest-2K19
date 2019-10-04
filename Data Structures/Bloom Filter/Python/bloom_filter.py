"""
    Overview
    --------
    A Bloom filter is a space-efficient probabilistic data structure, that is used to test whether an element is a member of a set. 
    False positive matches are possible, but false negatives are not – in other words, a query returns either "possibly in set" or "definitely not in set".

    Elements can be added to the set, but not removed (though this can be addressed with a "counting" filter); 
    the more elements that are added to the set, the larger the probability of false positives.

    Implementation
    --------------
    An empty Bloom filter is a bit array of m bits, all set to 0. There must also be k different hash functions defined,
    each of which maps or hashes some set element to one of the m array positions, generating a uniform random distribution. 
    Typically, k is a constant, much smaller than m, which is proportional to the number of elements to be added;
    the precise choice of k and the constant of proportionality of m are determined by the intended false positive rate of the filter.

    To add an element, feed it to each of the k hash functions to get k array positions. Set the bits at all these positions to 1.

    To query for an element (test whether it is in the set), feed it to each of the k hash functions to get k array positions. 
    If any of the bits at these positions is 0, the element is definitely not in the set – if it were, then all the bits would have been set to 1 when it was inserted.

    - Wikipedia (https://en.wikipedia.org/wiki/Bloom_filter)

    Interactive tutorial: https://llimllib.github.io/bloomfilter-tutorial/
"""
import random
import math

class BloomFilter:
    """
        For the given elements, we can guarantee that false positives
        will happen with this probability
    """
    FALSE_POSITIVE_PROBABILITY = 0.01

    def __init__(self, elements): 
        self.size = self.compute_bitset_size(len(elements)) 
        self.hash_function_count = self.compute_hash_function_count(self.size, len(elements))

        """
            Bitsets are not available in the Python standard library, so a list of booleans will be used instead.
            For an optimal implementation, refer to third-party implementations of bitsets for Python.
        """
        self.bit_set = [False for _ in range(self.size)]
        self.hash_functions = self.generate_hash_functions()
        for e in elements:
            self.add(e)

    def compute_bitset_size(self, element_count):
        """
            Compute optimal bitset size according to wikipedia formula for m"
        """
        return -round((element_count * math.log(self.FALSE_POSITIVE_PROBABILITY))/(math.log(2) ** 2))

    def compute_hash_function_count(self, size, element_count):
        """
            Compute optimal hash function count according to wikipedia formula for k"
        """
        return round((size // element_count) * math.log(2))

    def generate_hash_functions(self):
        """
            We need fast, uniformly distributed and independant hashing functions,
            and we also need an arbitrary amount of them.

            To achieve this, we can just generate a random mapping for each hashing function,
            and combine it with Python's hash function to support all datatypes.

            Note that holding the mappings in memory is memory unefficient, so
            the hashing functions should be determined in function of your needs.
        """
        hash_functions = []
        for i in range(self.hash_function_count):
            index_mapping = [idx for idx in range(self.size)]
            random.Random(i).shuffle(index_mapping)
            hash_func = lambda x: index_mapping[hash(x) % self.size]
            hash_functions.append(hash_func)

        return hash_functions
            

    def add(self, value_to_add):
        """
            To add, apply each hash function and set value to True
        """
        for hash_function in self.hash_functions:
            self.bit_set[hash_function(value_to_add)] = True

    def contains(self, value_to_check):
        """
            To check for value, apply each hash function and check that all hash functions
            lead to a True value.

            When this function returns False, we can 100% guarantee that the element is not in the set
            When this function returns True, we can only say that the element is MAYBE in the set.
        """
        for hash_function in self.hash_functions:
            if not self.bit_set[hash_function(value_to_check)]:
                return False
        return True
        
if __name__ == "__main__":
    elements = ["a", "b", "c"]
    bf = BloomFilter(elements)
    assert bf.contains("a")
    assert bf.contains("b")
    assert bf.contains("c")
    assert not bf.contains("d")
    assert not bf.contains("e")
    bf.add("d")
    assert bf.contains("d")
