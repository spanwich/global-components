/*
 * Copyright 2025, PhD Research Project
 *
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * STM32MP25x timer stub — ARM generic timer, no hardware timer component needed.
 */
#pragma once

#define HARDWARE_TIMER_COMPONENT                                       \
    component HWTimer {                                                \
        hardware;                                                      \
        emits TimerIRQ irq;                                          \
    }

#define HARDWARE_TIMER_INTERFACES                                      \
    consumes TimerIRQ hwtimer_irq;
#define HARDWARE_TIMER_ATTRIBUTES
#define HARDWARE_TIMER_COMPOSITION                                     \
        component HWTimer hwtimer;                                    \
        connection seL4HardwareInterrupt hwtimer_irq(from hwtimer.irq, \
                                                      to hwtimer_irq);
#define HARDWARE_TIMER_CONFIG                                            \
    hwtimer.irq_irq_number = 30;                                        \
    hwtimer.irq_irq_type = "arm";
#define HARDWARE_TIMER_PLAT_INTERFACES
