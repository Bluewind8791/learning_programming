class Book:

  def __init__(self, title, price, author):
      self.setData(title, price, author)
      print("made book data")

  def setData(self, title, price, author):
    self.title = title
    self.price = price
    self.author = author

  def printData(self):
    print('title: ', self.title)
    print('price: ', self.price)
    print('author: ', self.author)

