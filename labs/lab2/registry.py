class Runner:
    name: str
    time: str
    email: str

    def __init__(self, name, time, email):
        self.name = name
        self.time = time
        self.email = email

    def change_email(self, email):
        '''
        Change the email address of the current runner
        >>> David = Runner('David', 'under_30', 'david123@gmail.com')
        >>> David.email
        'david123@gmail.com'
        >>> David.change_email('asdf@gmail.com')
        >>> David.email
        'asdf@gmail.com'
        '''
        self.email = email

    def change_time(self, time):
        '''
        Change the time category of the current runner
        >>> Tim = Runner('Tim', 'under_30', 'tim@gmail.com')
        >>> Tim.time
        'under_30'
        >>> Tim.change_time('under_40')
        >>> Tim.time
        'under_40'
        '''
        self.time = time


class Registry:
    '''
    Sample usage:
    >>> race = Registry()
    >>> David = Runner('David', 'under_30', 'david123@gmail.com')
    >>> race.add_runner(David)

    '''
    runners: set[Runner]
    runner: Runner

    def __init__(self):
        self.runners = set()

    def add_runner(self, runner):
        self.runners.add(runner)

    def withdraw_runner(self, runner):
        if runner in self.runners:
            self.runners.remove(runner)


