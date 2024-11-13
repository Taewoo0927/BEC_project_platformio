#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

// Static - Limit the scope inside same .C file
// Const - Make it into constant so it's not editable
static const int led_pin = LED_BUILTIN;

static TaskHandle_t task_1 = NULL;
static TaskHandle_t task_2 = NULL;
static TaskHandle_t toggleLEDHandle = NULL;


const char msg[] = "HI MARCUS HELLO HI HIHI";

void startTask1(void *parameter){
  int msg_len = strlen(msg);
  
  while(1){

    Serial.println();
  
    for (int i = 0; i<msg_len; i++){
      Serial.println(msg[i]);
    }
  
    Serial.println();
  
    vTaskDelay(1000/ portTICK_PERIOD_MS);
  
  }
}

void startTask2(void *parameter){
  while(1){
    Serial.print('*');
    vTaskDelay(100/ portTICK_PERIOD_MS);
    }
}


// Void *parameter - universal variable type
void toggleLED(void *parameter){
  while(1){

    digitalWrite(led_pin, HIGH);
    // delay by 500 ticks - delaying by 500ms 
    vTaskDelay(500 / portTICK_PERIOD_MS);
    digitalWrite(led_pin, LOW);
    vTaskDelay(500 / portTICK_PERIOD_MS);

    Serial.println("Task 1");
  }
}

void setup() {

  Serial.begin(300);
  //pinMode(led_pin, OUTPUT);

  vTaskDelay(1000 / portTICK_PERIOD_MS);

  Serial.println("Test");

  Serial.println(uxTaskPriorityGet(NULL));

  xTaskCreate(startTask1, "Task 01", 1024, NULL, 1, &task_1);
  xTaskCreate(startTask2, "Task 02", 1024, NULL, 2, &task_2);

  //1024 -> Words size of the function, toggleLEDHandle -> Let us use suspend, resume, delete
  //xTaskCreate(toggleLED, "Toggle LED", 1024, NULL, 1, &toggleLEDHandle);
  }


void loop() {

  for (int i = 0; i < 3; i++){
    vTaskSuspend(task_2);
    vTaskDelay(2000 / portTICK_PERIOD_MS);
    vTaskResume(task_2);
    vTaskDelay(2000 / portTICK_PERIOD_MS);
  }
  if(task_1 != NULL){
    vTaskDelete(task_1);
    task_1 = NULL;
  }
}