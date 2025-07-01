#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Constants for memory simulation
#define MEMORY_SIZE 1000
#define MAX_BLOCKS 100

typedef struct 
{
    int id;             
    int size;          
    int start_address;  
} MemoryBlock;

MemoryBlock memory[MAX_BLOCKS];
int block_count = 0;

void initializeMemory() 
{
    memory[0].id = -1; 
    memory[0].size = MEMORY_SIZE;
    memory[0].start_address = 0;
    block_count = 1;
    printf("Memory initialized with %d units\n", MEMORY_SIZE);
}
void displayMemory() 
{
    printf("\nMemory Status:\n");
    printf("-------------\n");
    printf("Block ID\tStart\tSize\tStatus\n");
    
    for (int i = 0; i < block_count; i++) 
    {
        printf("%d\t\t%d\t%d\t%s\n", 
               abs(memory[i].id), 
               memory[i].start_address, 
               memory[i].size,
               memory[i].id < 0 ? "Free" : "Allocated");
    }
    
    int allocated = 0, free_space = 0, fragments = 0;
    
    for (int i = 0; i < block_count; i++) {
        if (memory[i].id < 0) {
            free_space += memory[i].size;
            fragments++;
        } else {
            allocated += memory[i].size;
        }
    }
    
    printf("\nTotal allocated: %d units\n", allocated);
    printf("Total free: %d units\n", free_space);
    printf("Number of free fragments: %d\n", fragments);
}
// Allocate memory using first-fit algorithm
int allocateMemory(int process_id, int size) 
{
    if (process_id <= 0) 
    {
        printf("Error: Process ID must be positive\n");
        return -1;
    }
    
    for (int i = 0; i < block_count; i++) 
    {
        if (memory[i].id == process_id) 
        {
            printf("Error: Process %d already has allocated memory\n", process_id);
            return -1;
        }
    }
    
    for (int i = 0; i < block_count; i++) 
    {
        if (memory[i].id < 0 && memory[i].size >= size) 
        {
            // Found a suitable free block
            int remaining_size = memory[i].size - size;
            int start_address = memory[i].start_address;
            
            if (remaining_size > 0) 
            {
                // Split the block
                memory[i].id = process_id;
                memory[i].size = size;
                
                // Shift all blocks after this to make space for new free block
                for (int j = block_count; j > i + 1; j--) 
                {
                    memory[j] = memory[j-1];
                }
                
                memory[i+1].id = -1;
                memory[i+1].size = remaining_size;
                memory[i+1].start_address = start_address + size;
                block_count++;
            } 
            else 
            {
                memory[i].id = process_id;
            }
            
            printf("Allocated %d units for Process %d at address %d\n", 
                  size, process_id, start_address);
            return start_address;
        }
    }
    
    printf("Error: Not enough memory available for Process %d\n", process_id);
    return -1;
}
bool deallocateMemory(int process_id) 
{
    int index = -1;
        for (int i = 0; i < block_count; i++) 
        {
        if (memory[i].id == process_id) 
        {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Error: Process %d does not have allocated memory\n", process_id);
        return false;
    }
    
    // Deallocate by marking as free
    memory[index].id = -1;
    
    // Merge with adjacent free blocks
    
    // Check if previous block is free
    if (index > 0 && memory[index-1].id < 0) {
        memory[index-1].size += memory[index].size;
        
        // Shift all blocks after index one position back
        for (int i = index; i < block_count - 1; i++) {
            memory[i] = memory[i+1];
        }
        
        block_count--;
        index = index - 1;  // Update index for next merge check
    }
    
    // Check if next block is free
    if (index < block_count - 1 && memory[index+1].id < 0) {
        memory[index].size += memory[index+1].size;
        
        // Shift all blocks after index+1 one position back
        for (int i = index+1; i < block_count - 1; i++) {
            memory[i] = memory[i+1];
        }
        
        block_count--;
    }
    
    printf("Deallocated memory for Process %d\n", process_id);
    return true;
}
// Handle fragmentation through compaction
void compactMemory() 
{
    if (block_count <= 1) return;
    
    int free_size = 0;
    
    for (int i = 0; i < block_count; i++) 
    {
        if (memory[i].id < 0) 
        {
            free_size += memory[i].size;
            
            // Remove this free block
            for (int j = i; j < block_count - 1; j++) 
            {
                memory[j] = memory[j+1];
            }
            block_count--;
            i--;  
        }
    }
    
    
    int current_address = 0;
    for (int i = 0; i < block_count; i++) 
    {
        memory[i].start_address = current_address;
        current_address += memory[i].size;
    }
    
    if (free_size > 0) 
    {
        memory[block_count].id = -1;
        memory[block_count].size = free_size;
        memory[block_count].start_address = current_address;
        block_count++;
    }
    
    printf("Memory compaction completed. Consolidated %d units of free space.\n", free_size);
}

int main(void)
{
    // Initialize memory
    initializeMemory();
    displayMemory();
    
    // Allocate memory for processes
    allocateMemory(1, 200);
    allocateMemory(2, 150);
    allocateMemory(3, 300);
    displayMemory();
    
    // Deallocate memory
    deallocateMemory(2);
    displayMemory();
    
    // Allocate again after deallocation
    allocateMemory(4, 120);
    displayMemory();
    
    // Allocate more to show fragmentation
    allocateMemory(5, 60);
    displayMemory();
    
    // Deallocate more processes
    deallocateMemory(1);
    deallocateMemory(3);
    displayMemory();
    
    // Perform compaction to handle fragmentation
    compactMemory();
    displayMemory();
    
    // Try allocation after compaction
    allocateMemory(6, 500);
    displayMemory();
    
    return 0;
}