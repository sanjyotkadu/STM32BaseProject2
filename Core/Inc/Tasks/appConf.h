/*
 * appConf.h
 *
 *  Created on: Feb 10, 2026
 *      Author: zamee
 */

#ifndef INC_APP_APPCONF_H_
#define INC_APP_APPCONF_H_

#include <stdint.h>

/* ================= TASK PERIODS ================= */
#define APP_TASK_PERIOD_MS        (100U)
#define COMM_TASK_PERIOD_MS       (50U)
#define WDG_TASK_PERIOD_MS        (500U)

/* ================= TASK PRIORITIES ============== */
#define APP_TASK_PRIORITY         (1U)
#define COMM_TASK_PRIORITY        (2U)
#define WDG_TASK_PRIORITY         (3U)

#endif /* INC_APP_APPCONF_H_ */
