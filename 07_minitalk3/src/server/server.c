/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:51:32 by astein            #+#    #+#             */
/*   Updated: 2023/07/26 01:04:41 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minitalk.h"

// static t_server	g_server;

static void	print_header(void)
{
	ft_printf("\n📭 📭 📭 📭 📭 📭 📭 📭 📭 📭 📭 📭\n");
	ft_putstr_fd("📭    ASTEINS MINITALK SERVER\n", 1);
	ft_putstr_fd("📭          (PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd(")\n", 1);
	// ft_putstr_fd("      press return (to exit\n", 1));
	ft_printf("📭 📭 📭 📭 📭 📭 📭 📭 📭 📭 📭 📭\n\n");
}

// static int	load_next_queuing_msgs(void)
// {
// 	return (0);
// }

// static void	handler_2(int signal)
// {
// 	static int		c;
// 	static int		bit_shift;
// 	static t_bool	flg_end_of_msg;

// 	// if (g_server.cur_pid != 0 && g_server.cur_pid != info->si_pid)
// 	// {
// 	// 	// MERKE DIR DIE PID FUER SPAETER
// 	// 	kill(g_server.cur_pid, BIT_0);
// 	// 	// printf("Merke dir die NUmmer");
// 	// 	return ;
// 	// }

// 	if (!g_server.transmitting)
// 	{
// 		// STARTE DIE TRANSMISSION
// 		g_server.transmitting = ft_true;
// 		ft_printf("\n📫 📫 📫 📫 📫 📫 📫 📫 📫 📫 📫 📫\n");
// 		ft_printf("📫 receiving message from: %i", g_server.cur_pid);
// 		ft_printf("\n📫 📫 📫 📫 📫 📫 📫 📫 📫 📫 📫 📫\n\n");
// 		kill(g_server.cur_pid, BIT_1);
// 		return ;
// 	}

// 	// AKTUELLE TRANSMISSION
// 	if (signal == BIT_1)
// 		c |= (1 << bit_shift);
// 	bit_shift++;
// 	if (bit_shift == 8 && c == 0)
// 		flg_end_of_msg = ft_true;
// 	else
// 		flg_end_of_msg = ft_false;
// 	if (bit_shift == 8 && c != 0)
// 		write(1, &c, 1);
// 	if (bit_shift == 8)
// 	{
// 		bit_shift = 0;
// 		c = (int)0;
// 		usleep(100);
// 	}
// 	if (flg_end_of_msg)
// 	{
// 		kill(g_server.cur_pid, BIT_1);
// 		ft_printf("\n\n📬 📬 📬 📬 📬 📬 📬 📬 📬 📬 📬 📬\n");
// 		ft_printf("📬 end of message from: %i", g_server.cur_pid);
// 		ft_printf("\n📬 📬 📬 📬 📬 📬 📬 📬 📬 📬 📬 📬\n\n");
// 		print_header();
// 		usleep(500);
// 		g_server.cur_pid = 0;
// 		printf("set to 0!\n");
// 		printf("cur pid: %d\n", g_server.cur_pid);
// 	}
// 	else
// 	{
// 		kill(g_server.cur_pid, BIT_0);
// 	}
// }

// int	main(void)
// {
// 	struct sigaction	signal_action;

// 	// g_server = malloc(sizeof(t_server));
// 	// if (!g_server)
// 	// 	exit(EXIT_FAILURE);
// 	print_header();
// 	signal_action.sa_handler = 0;
// 	signal_action.sa_flags = SA_SIGINFO | SA_NODEFER;
// 	signal_action.sa_sigaction = handler;
// 	sigaction(BIT_0, &signal_action, NULL);
// 	sigaction(BIT_1, &signal_action, NULL);
// 	while (1)
// 		pause();
// }

// // Define a structure to hold the signal information
// typedef struct SignalNode {
//     int signal;
//     struct SignalNode* next;
// } SignalNode;

// // Define a structure to hold the sender's signal queue
// typedef struct PID_Queue_NODE {
//     pid_t sender_pid;
//     SignalNode* head;
//     SignalNode* tail;
//     struct PID_Queue_NODE* next;
// } PID_Queue_NODE;

// // Global variable for the linked list of signal queues
// PID_Queue_NODE* PID_QUEUES_HEAD = NULL;
// PID_Queue_NODE* PID_QUEUES_TAIL = NULL;

// // t_all_msg_requests	*g_msg_request;

// // Function to add a signal to the queue for a specific sender_pid
// void enqueue_signal(pid_t sender_pid, int signal) {
//     PID_Queue_NODE* queue = PID_QUEUES_HEAD;
//     while (queue != NULL) {
//         if (queue->sender_pid == sender_pid) {
//             SignalNode* new_node = (SignalNode*)malloc(sizeof(SignalNode));
//             new_node->signal = signal;
//             new_node->next = NULL;

//             if (queue->tail == NULL) {
//                 queue->head = queue->tail = new_node;
//             } else {
//                 queue->tail->next = new_node;
//                 queue->tail = new_node;
//             }
//             return ;
//         }
//         queue = queue->next;
//     }

//     // If no queue exists for the sender_pid, create a new queue but first...
// 	//...let the client know that we take care of him
// 	kill(sender_pid, BIT_0);
//     PID_Queue_NODE* new_queue = (PID_Queue_NODE*)malloc(sizeof(PID_Queue_NODE));
//     new_queue->sender_pid = sender_pid;
//     new_queue->head = new_queue->tail = NULL;
//     new_queue->next = NULL;

//     if (PID_QUEUES_TAIL == NULL) {
//         PID_QUEUES_HEAD = PID_QUEUES_TAIL = new_queue;
//     } else {
//         PID_QUEUES_TAIL->next = new_queue;
//         PID_QUEUES_TAIL = new_queue;
//     }

//     // Enqueue the signal in the newly created queue
//     enqueue_signal(sender_pid, signal);

// }

//
	// Function to remove and return the signal at the front of the queue for a specific sender_pid
// int dequeue_signal(pid_t sender_pid) {
//     PID_Queue_NODE* queue = PID_QUEUES_HEAD;
//     while (queue != NULL) {
//         if (queue->sender_pid == sender_pid) {
//             if (queue->head == NULL) {
//                 return (-1); // Queue is empty
//             }

//             int signal = queue->head->signal;
//             SignalNode* temp = queue->head;
//             queue->head = queue->head->next;

//             if (queue->head == NULL) {
//                 queue->tail = NULL;
//             }

//             free(temp);
//             return (signal);
//         }
//         queue = queue->next;
//     }

//     return (-1); // Queue not found for the sender_pid
// }

// // Signal handler function
// static void handler(int signal, siginfo_t *info, void *context) {

// 	(void)context;
//     // Access the PID of the sending process from the siginfo_t structure
//     pid_t sender_pid = info->si_pid;

//     // Add the signal to the queue for the specific sender_pid
//     enqueue_signal(sender_pid, signal);
// }

t_server_2	g_server;

static void	receive_msg(int signal)
{
	static int		c;
	static int		bit_shift;
	static t_bool	flg_end_of_msg;

	if (signal == BIT_1)
		c |= (1 << bit_shift);
	bit_shift++;
	if (bit_shift == 8 && c == 0)
		flg_end_of_msg = ft_true;
	else
		flg_end_of_msg = ft_false;
	if (bit_shift == 8 && c != 0)
		write(1, &c, 1);
	if (bit_shift == 8)
	{
		bit_shift = 0;
		c = (int)0;
		usleep(100);
	}
	if (flg_end_of_msg)
	{
		kill(g_server.cur_pid, BIT_1);
		ft_printf("\n\n📬 📬 📬 📬 📬 📬 📬 📬 📬 📬 📬 📬\n");
		ft_printf("📬 end of message from: %i", g_server.cur_pid);
		ft_printf("\n📬 📬 📬 📬 📬 📬 📬 📬 📬 📬 📬 📬\n\n");
		print_header();
		usleep(500);
		g_server.cur_pid = 0;
		printf("set to 0!\n");
		printf("cur pid: %d\n", g_server.cur_pid);
	}
	else
	{
		kill(g_server.cur_pid, BIT_0);
	}
}

static void	handler_42(int signal, siginfo_t *info, void *context)
{
	(void)context;
	if (info->si_pid == g_server.cur_pid)
	{
		receive_msg(signal);
	}
	else
	{
		// store pid if possible
		if (g_server.queuing_count > 5)
		{
			write(1, "f", 1);
			write(1, "\n", 1);
			kill(BIT_0, info->si_pid);
		}
		else
		{
			g_server.queuing_count++;
			g_server.queuing_pids[g_server.cur_index++] = info->si_pid;
			if (g_server.cur_index > 4)
				g_server.cur_index = 0;
			kill(BIT_1, info->si_pid);
		}
	}
}

int	main(void)
{
	struct sigaction	signal_action;
	int					i;

	// Create a sigaction structure
	i = 0;
	g_server.cur_index = 0;
	g_server.queuing_count = 0;
	g_server.cur_pid = 0;
	// g_server.cur_pid = 0;
	// g_server.transmitting = ft_false;
	print_header();
	signal_action.sa_handler = 0;
	signal_action.sa_flags = SA_SIGINFO;
	signal_action.sa_sigaction = handler_42;
	sigaction(BIT_0, &signal_action, NULL);
	sigaction(BIT_1, &signal_action, NULL);
	while (1)
	{
		if (g_server.cur_pid == 0 && g_server.queuing_pids[i] == 0)
		{
			// chek for next msg to recive
			i++;
			if (i > 4)
				i = 0;
		}
		else if (g_server.cur_pid != 0)
		{
			// already busy - nothing else to do
		}
		else
		{
			g_server.cur_pid = g_server.queuing_pids[i];
			g_server.queuing_pids[i] = 0;
			g_server.queuing_count--;
			ft_printf("\n📫 📫 📫 📫 📫 📫 📫 📫 📫 📫 📫 📫\n");
			ft_printf("📫 receiving message from: %i", g_server.cur_pid);
			ft_printf("\n📫 📫 📫 📫 📫 📫 📫 📫 📫 📫 📫 📫\n\n");
			sleep(1);
			kill(SIGCONT, g_server.cur_pid);
		}
		sleep(1);
		printf("still there > checking queue pos: %i\n", i);
		// // Process signals from the queue for each sender_pid
		// PID_Queue_NODE* queue = PID_QUEUES_HEAD;
		// while (PID_QUEUES_HEAD != NULL) {
		//    g_server.cur_pid = PID_QUEUES_HEAD->sender_pid;
		//     int signal;
		//     // while ((signal = dequeue_signal(sender_pid)) != -1) {
		// 	while (g_server.cur_pid != 0) {
		// 		printf("cur pid: %d\n", g_server.cur_pid);
		// 		sleep(1);
		//         // Process the signal and sender_pid
		// 		signal = dequeue_signal(g_server.cur_pid);
		// 		if(signal != -1)
		//         	handler_2(signal);
		//         // printf("Received signal %d from PID %d\n", signal,
				// sender_pid);
		//     }
		//     PID_QUEUES_HEAD = PID_QUEUES_HEAD->next;
		// }
		// // Your program's main loop or other tasks
		// // ...
		// sleep(1);
	}
	return (0);
}
