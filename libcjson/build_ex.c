#include <stdio.h>
#include <stdlib.h>
#include <cJSON.h>

int main() {
	cJSON *root = cJSON_CreateObject();

	cJSON_AddItemToObject(root, "market", cJSON_CreateString("btcusdt"));
	cJSON_AddItemToObject(root, "side", cJSON_CreateString("buy"));
	cJSON_AddItemToObject(root, "volume", cJSON_CreateString("0.01"));
	cJSON_AddItemToObject(root, "price", cJSON_CreateString("40000"));
	cJSON_AddItemToObject(root, "groupId", cJSON_CreateNumber(87));

	printf("%s\n", cJSON_Print(root));

	return 0;
}
