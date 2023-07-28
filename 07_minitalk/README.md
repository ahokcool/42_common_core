# astein | minitalk

## Connection Procedure


| First Header  | Second Header |

| Step															| Client->Server					 				| Server->Client					|
| ------------- 												| ------------- 					 				| -------------  					|
| say hello														| ```BIT_0```						 		 				| ```BIT_0``` 							|
| ur ready server?												| ```BIT_1``` (each second)				 				| ```BIT_1``` (if ready) 					|
| send message literally 'bit by bit' 							| ```BIT_0``` (if bit of current char is 0)		 		| ```BIT_0``` (to confirm the reception)	|
| (waiting for an answer after each bit)						| ```BIT_1``` (if bit of current char is 1)		 		| ```BIT_0``` (to confirm the reception)	|
| send and additional '/0' to indicate the end of the message	| ```BIT_0``` ```BIT_0``` ```BIT_0``` ```BIT_0``` ```BIT_0``` ```BIT_0``` ```BIT_0``` ```BIT_0``` 	| ```BIT_1```								|

only if all characters of the message have been transmitted and the client recives the BIT_2 signal from the server it prints SUCCESS!