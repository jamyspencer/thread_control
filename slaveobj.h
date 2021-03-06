#ifndef SLAVEOBJ_H
#define SLAVEOBJ_H

#define MAX_SLAVES 15
#define SHM_SIZE sizeof(int)*(MAX_SLAVES*2+2)

int* shrd_mem_addr;

struct info{
	pid_t process_id;
	int queue_num;
}; 


struct list{
	struct info item;
	struct list* next;
	struct list* prev;
};

struct list *returnTail(struct list *head_ptr);
void addNode(struct list *head_ptr, pid_t pid);
struct list* destroyNode(struct list *head_ptr, pid_t pid);
struct list* destroyHead(struct list *head_ptr);

#define SLV_INFO struct info
#define SLV_LIST struct list

#endif
