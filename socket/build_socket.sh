#!/bin/bash

gcc -o client_run client.c
gcc -o server_run server.c

gcc -o udp_client_run udp_client.c
gcc -o udp_server_run udp_server.c