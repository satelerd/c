/*
Introduction to CUDA and GPU Computing on Azure

What is CUDA?
CUDA (Compute Unified Device Architecture) is a parallel computing platform and API model designed by NVIDIA. 
It allows developers to use NVIDIA GPUs for general purpose processing, significantly accelerating computational tasks by harnessing the power of these GPUs.

Why Use CUDA?
Unlike a CPU that processes tasks sequentially with a few cores, GPUs have thousands of smaller, efficient cores designed for parallel processing. 
This makes GPUs particularly powerful for algorithms that process large data blocks simultaneously, such as in scientific computing, video processing, and deep learning.

Key Concepts in CUDA
- Parallelism: CUDA uses the parallel nature of GPU architecture to perform large-scale computations more efficiently.
- Kernels: In CUDA, a kernel is essentially a function that runs on the GPU. Each kernel operates on different data using multiple threads.
- Threads and Blocks: CUDA executes kernels using a grid of thread blocks. These threads can execute independently but can also synchronize within their block to share data and coordinate execution.

Setting Up a CUDA Project on Azure
Using Azure allows you to access powerful NVIDIA GPUs without needing a physical GPU in your machine. Let's set up your environment to run CUDA programs on Azure.

Prerequisites:
- An Azure account with GPU capabilities (through Microsoft for Startups sponsorship).
- Basic familiarity with Azure's interface.
- Visual Studio Code (VSCode) installed on your local machine.

Steps to Set Up Your Azure GPU Environment:
1. Create a Virtual Machine with a GPU on Azure:
   - Log in to the Azure Portal.
   - Create a new resource and select 'Virtual Machines'.
   - Choose a GPU-enabled VM like the NC Series, which is specifically designed for compute-intensive applications. Select an appropriate region that supports GPU VMs.
   - Configure the VM with your desired settings and create it. Ubuntu is recommended as it is widely supported and compatible with the CUDA Toolkit.

2. Install the CUDA Toolkit on Your VM:
   - Once your VM is set up, connect to it via SSH.
   - Install the CUDA Toolkit by following the commands provided by the NVIDIA CUDA Toolkit installation guide for Linux. This often includes updating your package manager and installing the 'cuda' package.

3. Configure VSCode for Remote Development:
   - Install the Remote Development extension pack in VSCode on your local machine.
   - Connect VSCode to your Azure VM using the Remote-SSH feature, which allows you to edit and run code directly on the VM.

Writing Your First CUDA Program on Azure
Now that your environment is set up, let’s write a simple CUDA program to ensure everything is working properly.

Create and Run a CUDA Program:
- On your Azure VM, create a new file called 'hello.cu' and enter the following CUDA code:
*/

#include <stdio.h>

__global__ void helloFromGPU ()
{
    printf("Hello World from GPU!\n");
}

int main()
{
    printf("Hello World from CPU!\n");
    helloFromGPU <<<1, 10>>>();
    cudaDeviceSynchronize();
    return 0;
}

/*
Compile the program on the VM using the 'nvcc' compiler from the NVIDIA toolkit:
nvcc hello.cu -o hello

Run the compiled executable:
./hello

You should see "Hello World from CPU!" followed by "Hello World from GPU!" printed multiple times.

Reflection
By setting up and running a CUDA program on Azure, you've taken the first step in leveraging cloud-based GPU computing. 
This approach allows you to develop and test applications that require significant computational power without the need for local hardware. 
As you progress through the course, you'll explore more complex and computationally demanding CUDA programs, fully utilizing the capabilities of GPU computing on Azure.
*/
