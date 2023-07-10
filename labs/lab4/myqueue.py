"""CSC148 Lab 4: Abstract Data Types

=== CSC148 Winter 2023 ===
Department of Mathematical and Computational Sciences,
University of Toronto Mississauga

=== Module Description ===
In this module, you will develop an implementation of the Queue ADT.
It will be helpful to review the stack implementation from lecture.

After you've implemented the Queue, you'll write two different functions that
operate on a queue, paying attention to whether or not the queue should be
modified.
"""
from typing import Any, Optional


# attribute to store items.
class Queue:
    """A first-in-first-out (FIFO) queue of items.

    Stores data in a first-in, first-out order. When removing an item from the
    queue, the most recently-added item is the one that is removed.
    """
    _array = list

    def __init__(self) -> None:
        """Initialize a new empty queue."""
        self._array = []

    def is_empty(self) -> bool:
        """Return whether this queue contains no items.

        >>> q = Queue()
        >>> q.is_empty()
        True
        >>> q.enqueue('hello')
        >>> q.is_empty()
        False
        """
        return len(self._array) == 0

    def enqueue(self, item: Any) -> None:
        """Add <item> to the back of this queue.
        """
        self._array.append(item)

    def dequeue(self) -> Optional[Any]:
        """Remove and return the item at the front of this queue.

        Return None if this Queue is empty.
        (We illustrate a different mechanism for handling an erroneous case.)

        >>> q = Queue()
        >>> q.enqueue('hello')
        >>> q.enqueue('goodbye')
        >>> q.dequeue()
        'hello'
        """
        if self.is_empty():
            return None
        else:
            answer = self._array[0]
            self._array.remove(self._array[0])
            return answer


def product(integer_queue: Queue) -> int:
    """Return the product of integers in the queue.

    Remove all items from the queue.

    Precondition: integer_queue contains only integers.

    >>> q = Queue()
    >>> q.enqueue(2)
    >>> q.enqueue(4)
    >>> q.enqueue(6)
    >>> product(q)
    48
    >>> q.is_empty()
    True
    """
    if integer_queue.is_empty():
        return 0
    current_value = 1
    while not integer_queue.is_empty():
        current_value = current_value * integer_queue.dequeue()
    return current_value


def product_star(integer_queue: Queue) -> int:
    """Return the product of integers in the queue.

    Precondition: integer_queue contains only integers.

    >>> primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
    >>> prime_line = Queue()
    >>> for prime in primes:
    ...     prime_line.enqueue(prime)
    ...
    >>> product_star(prime_line)
    6469693230
    >>> prime_line.is_empty()
    False
    """
    current_value = 1
    second_queue = Queue()
    while not integer_queue.is_empty():
        n = integer_queue.dequeue()
        current_value = current_value * n
        second_queue.enqueue(n)
    while not second_queue.is_empty:
        integer_queue.enqueue(second_queue.dequeue())
    integer_queue.enqueue('1')
    return current_value


if __name__ == '__main__':
    import doctest
    doctest.testmod()
