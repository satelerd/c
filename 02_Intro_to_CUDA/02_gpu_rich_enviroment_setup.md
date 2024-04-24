# GPU-Rich Environment Setup Guide

## Introduction to GPU Environments
GPU environments are essential for tasks requiring massive parallel processing capabilities, such as machine learning, deep learning, and high-performance computing.

### Local vs. Cloud Solutions
Local solutions require a significant upfront investment and technical know-how to maintain the hardware. Cloud solutions like Azure provide flexible, scalable, and cost-effective access to powerful GPU resources on-demand.

Accessing GPU resources can vary greatly depending on whether you choose on-premises hardware or cloud-based solutions. We will focus on the latter, which offers a more accessible entry point for CUDA development.

### Cost Considerations
Cloud providers offer GPU access through a pay-as-you-go model, enabling cost-effective scaling. Planning and monitoring are essential to manage costs effectively.

## Setting Up on Azure
Azure provides various VM sizes with GPU capabilities suitable for different computational requirements.

### Choosing the VM Size and Type
We selected the Standard NC4as T4 v3 (NVIDIA Tesla T4) for its balance of computing power and cost-effectiveness.

### Network and Security Configuration
Ensure the correct configuration of the virtual network, subnet, and public IP. Set up Network Security Groups (NSGs) to allow SSH access while keeping other ports closed.

### Storage and Compute Options
Default SSD options are sufficient for most CUDA development needs. Adjust based on your specific data requirements.

## VM Instance Connection and Management

### Starting and Stopping the VM
Manage your VM's running state to control costs.
You can start and stop the VM through the Azure Portal or CLI.

```bash
# Starting the VM through CLI
az vm start --resource-group gpu_rich --name gpu-rich

# Stopping and deallocating the VM
az vm deallocate --resource-group gpu_rich --name gpu-rich
```

### Connecting to the VM
SSH is the standard method for connecting to and managing your Azure VM.

```bash
# Connecting to the VM
ssh -i ~/.ssh/gpu_rich_key.pem <your-username>@<your-vm-ip-address>
```


## Installing CUDA Toolkit
Install the necessary tools to compile and run CUDA programs.

```bash
# Update and install required packages
sudo apt-get update && sudo apt-get upgrade -y
sudo apt-get install build-essential -y
sudo apt install nvidia-cuda-toolkit -y
```

# Verifying the Installation
Verify the installation by checking the CUDA version and GPU driver.

```bash
# Check the CUDA version
nvcc --version

# Check the GPU driver
nvidia-smi
```

# Hello World from CPU and GPU
Create a simple program that runs computations on both the CPU and GPU to confirm that your environment is set up correctly.

```bash
# Creating a CUDA file
nano hello_cuda.cu
```

Inside the nano editor, write the following code:

```cuda
#include <stdio.h>

__global__ void helloFromGPU() {
    printf("Hello World from GPU!\n");
}

int main() {
    printf("Hello World from CPU!\n");
    helloFromGPU <<<1, 10>>>();
    cudaDeviceSynchronize();
    return 0;
}
```

Save and exit nano (Ctrl + X, then Y to confirm, and Enter to write to the file). 

Compile and run your program:

```bash
# Compile the CUDA program
nvcc hello_cuda.cu -o hello_cuda

# Run the compiled executable
./hello_cuda
```
You should see the output "Hello World from CPU!" followed by "Hello World from GPU!" printed multiple times.

Remember to replace < your-vm-ip-address > with the actual public IP address of your VM.

