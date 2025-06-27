# Week 4

This week will give an introduction to discrete event simulators, some of the networks basics required to build a Network Simulator and an implementation of a simple discrete event simulator will be provided to give you an idea how these simulators actually work.

### Discrete Event Simulator

A Discrete Event Simulator (DES) is a type of computer simulation used to model the operation of systems as a sequence of distinct events in time. Each event occurs at a particular instant and marks a change of state in the system. Unlike continuous simulations, which update the system state at every small time step, discrete event simulation jumps from one event to the next. Its used to model real systems with proper configurations and often used in research. `

### Computer Networks Basics
Basic knowledge of the following topics required:
- Network Topology and Nodes
- Routing Logic
- Packet Abstraction
- Network Delays

You can search the above topics and get an idea, you will require them while designing your simulator

### A Simple Discrete Event Simulator: CPU Job Scheduling Simulator
A simple discrete event simulator has been introduced to give you all an idea about the flow of a DES. Its very important to go through the codebase and understand as much as you can, you can also use it as your starting template for the simulator you will design. The sample DES simulates a simple Round Robin CPU Job Scheduling policy, play with it and see how it works! 

Note: You can even extend the simulator and add your own policies and stuff, I can guarantee this is a good start to get an idea on how to read codebases and understand the complete flow, happy learning!

### Resources
- https://youtu.be/Lo_pIjzej1A?si=qcIB673zmFUzxZMj (Lectures by Prof Vinay for Computer Networks)
- https://cs.baylor.edu/~maurer/aida/desauto/chapter3.pdf (Discrete Event Simulator)
- https://people.orie.cornell.edu/mru8/orie3120/lec/lec10.pdf (Discrete Event Simulator)