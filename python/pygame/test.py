import pygame

pygame.init()

display_width = 800
display_height = 600

black = (0, 0, 0)
white = (255, 255, 255)
red = (255, 0, 0)
green = (0, 255, 0)
blue = (0, 0, 255)

gameDisplay = pygame.display.set_mode((display_width, display_height))
pygame.display.set_caption('DafuQ')
clock = pygame.time.Clock()

carImg = pygame.image.load('racecar.png')

def car(x, y):
    gameDisplay.blit(carImg, (x, y))

x = (display_width * 0.45)
y = (display_height * 0.8)

change_x = 0

crashed = False

while not crashed:
    for event in pygame.event.get():
        # quit
        if event.type == pygame.QUIT:
            crashed = True

        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                change_x += -5
            if event.key == pygame.K_RIGHT:
                change_x += 5

        if event.type == pygame.KEYUP:
            if event.key == pygame.K_LEFT:
                change_x += 5
            if event.key == pygame.K_RIGHT:
                change_x += -5


    x += change_x
    gameDisplay.fill(white)
    car(x, y)
    pygame.display.update()
    clock.tick(60)

pygame.quit()
quit()
