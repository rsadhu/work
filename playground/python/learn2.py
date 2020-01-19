class Test():
	def __init__(self):
		print("Test::init")
	def parse(self, data):
		print("self::parse")



if __name__ == "__main__":
	d = Test()
	d.parse("Hello You Silly billy")
