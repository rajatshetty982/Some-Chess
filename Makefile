CC = gcc

OBJS = src/main.c src/game.c src/move.c src/render.c src/pieces.c src/utils.c src/board.c

TARGET = build/chess-ui

CFLAGS = -w

LDFLAGS = -lSDL2 -lSDL2_image

$(TARGET) : $(OBJS)
	@mkdir -p build
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $(TARGET)
	./$(TARGET)


# Rule to clean up generated files
clean:
	rm -f $(TARGET)
	rmdir build 2>/dev/null || true