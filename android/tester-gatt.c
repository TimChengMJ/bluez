/*
 * Copyright (C) 2014 Intel Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include "tester-main.h"

static struct queue *list; /* List of gatt test cases */

static struct step dummy_steps[] = {
	{
		.action = dummy_action,
	},
};
static struct test_case gatt_init = {
	.step = dummy_steps,
	.title = "Socket Init",
	.step_num = get_test_case_step_num(dummy_steps),
};

static struct test_case *test_cases[] = {
	&gatt_init,
};

struct queue *get_gatt_tests(void)
{
	uint16_t i = 0;

	list = queue_new();

	for (; i < sizeof(test_cases) / sizeof(test_cases[0]); ++i)
		if (!queue_push_tail(list, test_cases[i]))
			return NULL;

	return list;
}

void remove_gatt_tests(void)
{
	queue_destroy(list, NULL);
}
