#include <stdio.h>
#include <stdlib.h>
#include <cJSON.h>

int main() {
	char *jsonStr = "{\"market\":\"btcusdt\",\"trades\":[{\"price\":59842.35,\"volume\":0.001851,\"time\":\"2021-03-13T12:53:41.237Z\",\"trend\":-1}],\"time\":\"2021-03-13T12:53:41.458Z\"}";
	cJSON *root = NULL;
	cJSON *item = NULL;
	int i;

	root = cJSON_Parse(jsonStr);
	if (!root) {
		printf("Error: %s\n", cJSON_GetErrorPtr());
	} else {
		printf("%s\n\n", cJSON_Print(root));
		printf("%s\n\n", cJSON_PrintUnformatted(root));

		printf("Get \"market\":\n");
		item = cJSON_GetObjectItem(root, "market");
		printf("%s\n", cJSON_Print(item));
		printf("%s: %s\n", item->string, item->valuestring);
		printf("\n");

		printf("Get \"trades\":\n");
		item = cJSON_GetObjectItem(root, "trades");
		printf("%s\n", cJSON_Print(item));
		printf("Array size: %d\n", cJSON_GetArraySize(item));
		for (i = 0; i < cJSON_GetArraySize(item); i++) {
			printf("- Item %d: %s\n", i, cJSON_Print(cJSON_GetArrayItem(item, i)));
		}
		printf("\n");
	}
	return 0;	
}
