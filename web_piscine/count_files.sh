#!bin/bash

ls | wc -l | awk '{print $1}'
