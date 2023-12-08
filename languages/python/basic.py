class Base:
    def __init__(self):
        print("Constructor")
    def __del__(self):
        print("Destructor")

    def display(self):
        print("Test::display")
        self.name ="function display"
    def log(msg):
        print(msg)


class Test(Base):
    def __init__(self):
        print("Constructor Test")
    def __del__(self):
        print("Destructor Test")
    def foo(self):
        self.display()


if __name__ == "__main__":
    print("main")
    t = Test()
    t.foo()
    Test.log("hello is it a  static function log")