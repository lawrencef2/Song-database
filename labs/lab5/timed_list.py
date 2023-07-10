"""CSC148 Lab 5: Linked Lists

=== CSC148 Winter 2023 ===
Department of Mathematical and Computational Sciences,
University of Toronto Mississauga

=== Module description ===

This module runs timing experiments to determine how the time taken
to call `len` on a Python list vs. a LinkedList grows as the list size grows.
"""
from timeit import timeit
from linked_lists import LinkedList

NUM_TRIALS = 3000                        # The number of trials to run.
SIZES = [1000, 2000, 4000, 8000, 16000]  # The list sizes to try.


def profile_len(list_class: type, size: int) -> float:
    """Return the time taken to call len on a list of the given class and size.

    Precondition: list_class is either list or LinkedList.
    """
    my_list = []
    for i in range(size):
        my_list.append('0')

    # TODO: call timeit appropriately to check the runtime of len on the list.
    for size in SIZES:
        my_list = []
        for i in range(size):
            my_list.append('0')
        my_linked_list = LinkedList(my_list)
        time = 0
        time += timeit('len(my_list)', number=1, globals=locals())
        print(f'Len of list: List size {len(my_list):>7}, time {time}')
        time = 0
        time += timeit('len(my_linked_list)', number=1, globals=locals())
        print(f'Len of LinkedList: Linked list size {len(my_linked_list):>7}, time {time}')

    # Look at the Lab 4 starter code if you don't remember how to use timeit:
    # https://mcs.utm.utoronto.ca/~148/labs/w4_ADTs/starter-code/timequeue.py
    return 0.0


if __name__ == '__main__':
    # Try both Python's list and our LinkedList
    for list_class in [list, LinkedList]:
        # Try each list size
        for s in SIZES:
            time = profile_len(list_class, s)
            print(f'[{list_class.__name__}] Size {s:>6}: {time}')
