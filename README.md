# STM32 Multi-Mode Traffic Light Controller (FSM + Cooperative Scheduler)

A bare-metal / HAL-based traffic light controller for a 2-road intersection (Road 1 & Road 2) running on **STM32F103**.  
The project uses a **Finite State Machine (FSM)** for system logic and a lightweight **Cooperative Scheduler** (non-RTOS) to run periodic tasks without blocking delays.

## Features
- **2-road intersection** traffic light simulation (Red / Yellow / Green)
- **3 operating modes**
  - **AUTO**: normal traffic light cycle with countdown display
  - **MANUAL**: manually give priority to a road (includes safety **yellow transition** before switching)
  - **CONFIG**: change Red/Green/Yellow durations at runtime (no reflashing)
- **LCD 16x2 over I2C** for status + countdown / configuration view
- **4 physical buttons** with software debouncing
- **Cooperative scheduler** (timer-driven) to avoid `HAL_Delay()` and keep timing deterministic

## Demo
- Video demo: *https://drive.google.com/file/d/1-FRQuWYKPtNmB4mICJRiysSOB4LEfiR6/view?usp=drive_link*

## Hardware / Requirements
- MCU: **STM32F103** (tested on STM32F103 board)
- LEDs: 2 traffic light clusters (Road 1 & Road 2)
- LCD: **16x2 I2C LCD** (project uses I2C address `0x21` in code)
- Buttons: 4 push buttons
- Programmer: ST-LINK (or equivalent)

## Button Mapping (by function)
The firmware uses 4 buttons with these roles:
- **Button 0 (Mode)**: switch modes / switch which color to configure
- **Button 1 (Increase)**: increase value / next step in manual control
- **Button 2 (Decrease)**: decrease value
- **Button 3 (Save)**: save the configured value

> Note: In code, button indexes are `0..3` and map to `BUTTON1..BUTTON4` pins.

## Operating Modes
### 1) AUTO Mode
- Runs the standard cycle for Road 1 & Road 2.
- LCD shows countdown timers for both roads.
- Press **Mode** to enter **MANUAL**.

### 2) MANUAL Mode
- Allows changing which road is granted movement priority.
- Press **Increase** to switch priority to the other road.
- A **yellow safety period** is applied before switching fully.
- Press **Mode** to enter **CONFIG**.

### 3) CONFIG Mode
- Configure timing values for:
  - **RED duration**
  - **GREEN duration**
  - **YELLOW duration**
- **Increase/Decrease** changes the current value (wraps around 0–99).
- **Save** applies the current setting.
- **Mode** switches which color you are configuring, or exits back to **AUTO** after YELLOW.

## Software Architecture
### Cooperative Scheduler
A simple cooperative scheduler runs tasks periodically:
- `timeCounter` (1 ms)
- `getKeyInput` (1 ms) – button scan + debouncing
- `fsm_run` (1 ms) – main FSM logic
- `Traffic_LCD_Display_Task` (10 ms) – LCD refresh (stable, no flicker)

A timer interrupt updates the scheduler tick, while the main loop dispatches ready tasks.

### Finite State Machine (FSM)
Main states:
- `INIT`
- `AUTO_STATE`
- `MANUAL_STATE`
- `CONFIG_STATE`

Manual sub-modes implement blinking/safety transitions between road priorities.

## Build & Flash (STM32CubeIDE)
1. Open **STM32CubeIDE**
2. **Import** the project:
   - `File > Import > Existing Projects into Workspace`
   - Select the repo folder
3. Open `final_project.ioc` (optional) to review CubeMX configuration
4. Build the project
5. Connect ST-LINK and **Flash**:
   - `Run > Debug` (or `Run > Run`)

## Project Structure (key files)
- `Core/Src/main.c` – scheduler task setup + initialization
- `Core/Src/scheduler.c` – cooperative scheduler implementation
- `Core/Src/state_machine.c` – FSM logic
- `Core/Src/button.c` – button driver + debouncing
- `Core/Src/traffic_lcd.c` + `Core/Src/i2c_lcd.c` – LCD UI + I2C driver
- `final_project.ioc` – CubeMX configuration (pins/peripherals)

## Authors
- **Trương Thiên Ân**
- **Nguyễn Tô Quốc Việt**
