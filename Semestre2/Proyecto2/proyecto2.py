#! /usr/bin/env python
# -*- coding: utf-8 -*-
import pygame
import sys
import time
import random
import json
import os
from pygame.locals import *

pygame.init()

VELOCIDAD = 10
CONTADOR = 100
aumento = random.randint(100, 800)

def crear_random():
    global aumento
    while aumento >= 500:
        aumento = random.randint(100,800)

def color():
# Codigos de color RGB
    negro = pygame.Color(0, 0, 0)
    blanco = pygame.Color(255, 255, 255)
    rojo = pygame.Color(200,68,80)
    celeste = pygame.Color(20, 200, 200)
    return negro, blanco, rojo, celeste

def crear_ventana():
    ventana = pygame.display.set_mode((1300, 700))
    pygame.display.set_caption("Laberinto")
    ventana.fill((0, 0, 0))
    return ventana

def crear_jugador(ventana):
    jugador = pygame.image.load("Imagen/punto.png")
    posicionX = 100 
    posicionY = CONTADOR
    ventana.blit(jugador, (posicionX,posicionY))
    return jugador, posicionX, posicionY
 
def imagen(ventana,jugador, posicionX, posicionY, blanco, negro, celeste, movs,aumento, laberinto):
    aux = True
    colision = pygame.image.load("Imagen/colision.png")
    posicion__X = 100 
    posicion__Y = 0
    ventana.blit(colision, (posicion__X,posicion__Y))
    while aux:
        pygame.display.update()
        time.sleep(0.8)
        aux = False
    condiciones_colisiones(posicionX, posicionY, blanco, jugador, negro, celeste, movs, aumento, laberinto) #Evita mover la ficha
    return colision

def camino_laberinto(ventana, blanco, CONTADOR, aumento):
    post_vertical = 200
    post_horizontal = 1100

    while (CONTADOR < post_horizontal):
        pygame.draw.line(ventana, blanco, (CONTADOR,CONTADOR), (CONTADOR,post_vertical+25),50)
        pygame.draw.line(ventana, blanco, (post_horizontal,CONTADOR * 2), (CONTADOR,CONTADOR *2), 50) 
        CONTADOR += aumento

def condiciones_colisiones(posicionX, posicionY, blanco, jugador, negro, celeste, movs, aumento, laberinto):
    i = movs[len(movs)-1]

    if i == 'I':
        posicionX += VELOCIDAD
        movimiento(jugador,posicionX, posicionY, blanco, negro, celeste, movs, aumento, laberinto)
    if i == 'D':
        posicionX -= VELOCIDAD
        movimiento(jugador,posicionX, posicionY, blanco, negro, celeste, movs, aumento, laberinto)
    if i == 'S':
        posicionY += VELOCIDAD
        movimiento(jugador,posicionX, posicionY, blanco, negro, celeste, movs, aumento, laberinto)
    if i == 'B':
        posicionY -= VELOCIDAD
        movimiento(jugador,posicionX, posicionY, blanco, negro, celeste, movs, aumento, laberinto)

def ganar(ventana, posicionX, posicionY, rojo, negro, celeste, blanco, movs, aumento, laberinto):
    
    if (posicionY == 700 ):
        fuente_ganar = pygame.font.Font(None, 27)
        texto_ganar = fuente_ganar.render(" HAS GANADO!!",0, rojo, celeste)
        texto_salida_final = fuente_ganar.render(" -Salir (ESC)",0, rojo, celeste)
        texto_recrear = fuente_ganar.render(" -Recrear (R)",0, rojo, celeste)
        texto_volver_jugar = fuente_ganar.render("- Volver a jugar (ENTER)", 0, rojo, celeste)

        while True:
            for event in pygame.event.get():
                if event.type == QUIT:
                    pygame.quit()
                    sys.exit()

                if event.type == pygame.KEYDOWN:
                    if event.key == K_ESCAPE:
                        pygame.quit()
                        sys.exit()

                    elif event.key == K_r:
                        emular_recorrido(movs, ventana, blanco, negro, celeste, aumento)

                    elif event.key == K_RETURN:
                        negro, blanco, rojo, celeste = color()
                        ventana = crear_ventana()
                        menu(ventana, negro, rojo)

            ventana.blit(texto_ganar,(150, 100))
            ventana.blit(texto_salida_final,(150, 130))
            ventana.blit(texto_recrear,(150, 150))
            ventana.blit(texto_volver_jugar,(150, 170))
            pygame.display.update()

def creacion_json(movs, laberinto, aumento):
    idlaberinto = 'laberinto' + str (aumento)
    
    print(aumento)
    if idlaberinto not in laberinto:
        laberinto[idlaberinto]=[]

    nueva_ensenanza = len(laberinto[idlaberinto])
     
    laberinto[idlaberinto].append({
        'ensenanza'+str(nueva_ensenanza): movs
    })
 
    with open('prueba.json',"w") as file:
        json.dump (laberinto, file, indent = 4)
 
    with open('prueba.json',"r") as file:
        labJson = json.load(file)

def movimiento(jugador, posicionX, posicionY, blanco, negro, celeste, movs, aumento, laberinto):

    while True:	
        ventana.fill(negro)
        camino_laberinto(ventana, blanco, CONTADOR, aumento)
        ventana.blit(jugador, (posicionX, posicionY))
        
        if ventana.get_at((posicionX, posicionY)) != blanco: # Si es colision
            colision = imagen(ventana,jugador, posicionX, posicionY, blanco, negro, celeste, movs, aumento, laberinto)
       
        for event in pygame.event.get():
            if event.type == QUIT:
                pygame.quit()
                sys.exit()

            elif event.type == pygame.KEYDOWN:
                if event.key == K_RIGHT:
                    posicionX += VELOCIDAD

                elif event.key == K_LEFT:
                    posicionX -= VELOCIDAD

                elif event.key == K_DOWN:
                    posicionY += VELOCIDAD

                elif event.key == K_UP:
                    posicionY -= VELOCIDAD

            elif event.type == pygame.KEYUP:
                if event.key == K_RIGHT:
                    movs.append("D")

                elif event.key == K_LEFT:
                    movs.append("I")

                elif event.key == K_DOWN:
                    movs.append("B")

                elif event.key == K_UP:
                    movs.append("S")
		
        creacion_json(movs, laberinto, aumento)
        ganar(ventana, posicionX, posicionY, rojo, negro, celeste, blanco, movs, aumento, laberinto)
        pygame.display.update()
    #    print(aumento)
      #  print(movs)

def emular_recorrido(movs, ventana, blanco, negro, celeste, aumento):
    jugar = True
#    print("CONT ANTES:",CONTADOR)
    print ( aumento)
    while jugar:
        ventana = crear_ventana()
        jugador,posicionX, posicionY = crear_jugador(ventana)
        ventana.blit(jugador, (posicionX,posicionY))
        camino_laberinto(ventana, blanco, CONTADOR, aumento)
        print("CONT ANTES:",CONTADOR)
        print ("aumen antes:", aumento)
        print("Cantidad de movimientos realizados: ",len(movs))

        for event in pygame.event.get():
            if event.type == QUIT:
                pygame.quit()
                sys.exit()	

        for i in movs:
            if i == 'D':
                time.sleep(0.1)
                posicionX += VELOCIDAD

            if i == 'I':
                time.sleep(0.1)
                posicionX -= VELOCIDAD

            if i == 'B':
                time.sleep(0.1)
                posicionY += VELOCIDAD

            if i == 'S':
                time.sleep(0.1)
                posicionY -= VELOCIDAD
			
            ventana.blit(jugador, (posicionX,posicionY))
            pygame.display.update()
            jugar = False

        if jugar == False:
            time.sleep(0.5)
            break

def menu(ventana, negro, rojo):
    titulo = pygame.image.load("Imagen/titulo.png")
    postX_titulo = 240
    postY_titulo = 120
    fuente = pygame.font.Font(None, 30)
    texto_jugar = fuente.render("- Para jugar presione ENTER",0, rojo)
    texto_salir = fuente.render("- Para salir presione ESC",0, rojo) 
    movs = []
    laberinto = {}
    crear_random()
    while True:
        for event in pygame.event.get():
            if event.type == pygame.KEYDOWN:
                if event.key == K_RETURN:
                    jugador, posicionX, posicionY = crear_jugador(ventana)
                    movimiento(jugador, posicionX, posicionY, blanco, negro, celeste, movs, aumento, laberinto)

                elif event.key == K_ESCAPE:
                    pygame.quit()
                    sys.exit()
		
        ventana.blit(titulo, (postX_titulo,postY_titulo))
        ventana.blit(texto_jugar,(400,440))
        ventana.blit(texto_salir,(400,460))
        pygame.display.update()

if __name__== "__main__": 	
    negro,blanco, rojo, celeste = color()
    ventana = crear_ventana()
    menu(ventana, negro, rojo)
