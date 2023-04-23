# Particle Systems and Special Effects

## Introduction
I'm Victor Martin Ballesta, student from CITM, and this is my personal research for Proyect II

## Particle System
A particle system is an object that emit particles, giving them their properties and managing them.

![tumblr_8bd5434864ee91df6ca0ffaaf2d8894e_b824f32a_540](https://user-images.githubusercontent.com/99729766/233849339-0a7d91b8-c64f-44dc-8abc-cb0b5a83cfe6.gif)

A particle can be simple texture with basic editions, like size, color and rotation.

![EaiN-hrpcmqv3205702](https://user-images.githubusercontent.com/99729766/233849351-d2531f94-f9b5-428d-8bc8-76f6547dc899.gif)

A particle usually requires a lot of particles to work properly. Because creating new objects is time consuming, we will create an object pool with a maximum number of particles.

![Campfire_with_smoke](https://user-images.githubusercontent.com/99729766/233849346-7c565629-48d3-4ed4-b736-ad3ded34ad38.gif)

## Object Pool
An object pool is a component that occupies a certain memory with a certain type of object. 

Object pools are useful for when you will create a lot of similar objects that are created and deleted continuously. Particles are a perfect example of that. 

The particles will be lended by the object pool and will return once the particle system is destroyed. 

![objectpoolingmikegeig](https://user-images.githubusercontent.com/99729766/233849637-2d725bbc-3761-40ae-a731-dfa42320f26c.png)


## How to implement into your proyect

### Add the files related to particles
Add the following files found in this Github proyect: Particle.cpp, Particle.h, ParticleSystem.cpp, ParticleSystem.h, ParticleSystemManager.cpp, ParticleSystemManager.h

### Add the Module ParticleSystemManager
Add the ParticleSystemManager to your App's Module System (and adapt any possible inconsistencies)

### Add the PrintAlphaTexture in your Render Module
To be able to print the particles with changing colors, a new function has to be added to the Render module (This is made to work with SDL). You can find the function in Render.cpp


## Extra Posible Inclusions

### XML Inclusion
A possible extra inclusion could be making the blueprints in an XML file, loading them and having them separated from the code.

### Animated Particles
Another thing that could be added is making the alphas as a spritesheet and making the particles animated.

### Various Interpolation Funtions
Now, when the particles change over time, they do it in a linear manner (LERP). Another addition can be to make different interpolation with different functions.

## References

Making a Particle System WITHOUT a Game Engine! - Small Hedge Games (https://www.youtube.com/watch?v=s8LGqotLc-g)

Object Pool - Optimization Patterns - Game Programming Patterns (https://gameprogrammingpatterns.com/object-pool.html)
