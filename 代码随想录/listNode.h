#pragma once




struct listnode {
	int val;
	listnode* next;
	listnode(int v) : val(v), next(nullptr) {};
};