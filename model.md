# The Processing-in-Memory Model

 ![PIM Model](image URL)

## Key components of the model
* CPU-side: Parallel cores with fast access to a small shared memory.
* PIM-side: Multiple PIM modules, each with a core and a local memory of size Θ(n/P) for an input of size n.
* Network: Connects the CPU-side and PIM-side, enabling communication between them.

## Challenges of the Model
* Load balancing: ensure that the workload is evenly distributed across all processing units.
* Communication Efficiency: Minimizes the communication time between different processing units.

## Model's Novelty
* Unlike traditional models, the PIM model uniquely combines shared and distributed memory aspects, enabling the design of efficient parallel algorithms.
* It addresses the limitations of previous approaches by ensuring that data accesses are mostly local, thus significantly reducing data movement costs.

## Data Structures
* 
