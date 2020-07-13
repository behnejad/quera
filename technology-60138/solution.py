class Piece:
    def __init__(self, sort, color, position):
        self.sort = sort
        self.color = color
        self.position = position

    def invert_color(self):
        self.color = "white" if self.color == "black" else "black"

def euqal(piece1, piece2):
    return piece1.sort == piece2.sort and piece1.color == piece2.color

class Board():
    def __init__(self):
        self.position = {}
        self.position[(10, 10)] = Piece("K", "black", (10, 10))
        self.position[(-10, -10)] = Piece("K", "white", (-10, -10))
        self.kw = (-10, -10)
        self.kb = (10, 10)

    def add(self, piece):
        if piece.sort == "K" or piece.position in self.position:
            print("invalid query")
        else:
            self.position[piece.position] = piece

    def remove(self, position):
        if position in self.position and self.position[position].sort != "K":
            del self.position[position]
        else:
            print("invalid query")

    def move(self, piece, position2):
        if piece.position in self.position and self.position[piece.position] == piece:
            if position2 not in self.position:
                self.position[position2] = piece
                del self.position[piece.position]
                piece.position = position2
                return
            elif self.position[position2].sort != "K" and self.position[position2].color != piece.color:
                self.position[position2] = piece
                del self.position[piece.position]
                piece.position = position2
                return
        print("invalid query")

    def is_mate(self, color):
        if color == "white":
            for i in range(self.kw[0] - 1, self.kw[0] + 2):
                for j in range(self.kw[1] - 1, self.kw[1] + 2):
                    if (i, j) in self.position and self.position[(i, j)].sort != "K" and self.position[(i, j)].color == "black":
                        return True
        elif color == "black":
            for i in range(self.kb[0] - 1, self.kb[0] + 2):
                for j in range(self.kb[1] - 1, self.kb[1] + 2):
                    if (i, j) in self.position and self.position[(i, j)].sort != "K" and self.position[(i, j)].color == "white":
                        return True
        return False
