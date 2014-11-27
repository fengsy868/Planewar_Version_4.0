CC = g++
EXECS = PlaneWars
LIBS = -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
INCLUDE = -I/usr/include/SDL
OBJS = Objet.o Plane.o Hero.o Timer.o EnemyPlane.o Map.o GoblinPlane.o MediumPlane.o SuperPlane.o Bullet.o PlaneWars.o Music.o Menu.o

all: $(EXECS)

.c.o:
	$(CC) -c $(INCLUDE) $(LIBS)

$(EXECS): $(OBJS)
	$(CC) -g -o $(EXECS) $(OBJS) $(LIBS)

clean:
	rm -f *.o a.out $(EXECS) core *~


