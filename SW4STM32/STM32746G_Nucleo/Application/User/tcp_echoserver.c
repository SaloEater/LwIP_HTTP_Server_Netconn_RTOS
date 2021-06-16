/**
 * Copyright (c) 2001-2004 Swedish Institute of Computer Science.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of and a contribution to the lwIP TCP/IP stack.
 *
 * Credits go to Adam Dunkels (and the current maintainers) of this software.
 *
 * Christiaan Simons rewrote this file to get a more stable echo application.
 *
 **/

/* This file was modified by ST */

#include "tcp_echoserver.h"
#include "lwip/debug.h"
#include "lwip/stats.h"
#include "lwip/tcp.h"
#include "main.h"
#include <string.h>

#include<stdlib.h>

#if LWIP_TCP

static struct tcp_pcb *tcp_echoserver_pcb;

/* ECHO protocol states */
enum tcp_echoserver_states
{
	ES_NONE = 0,
	ES_ACCEPTED,
	ES_RECEIVED,
	ES_CLOSING
};

/* structure for maintaing connection infos to be passed as argument
   to LwIP callbacks*/
struct tcp_echoserver_struct
{
	u8_t state;             /* current connection state */
	u8_t retries;
	struct tcp_pcb *pcb;    /* pointer on the current tcp_pcb */
	struct pbuf *p;         /* pointer on the received/to be transmitted pbuf */
};


static err_t tcp_echoserver_accept(void *arg, struct tcp_pcb *newpcb, err_t err);
static err_t tcp_echoserver_recv(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err);
static void tcp_echoserver_error(void *arg, err_t err);
static err_t tcp_echoserver_poll(void *arg, struct tcp_pcb *tpcb);
static err_t tcp_echoserver_sent(void *arg, struct tcp_pcb *tpcb, u16_t len);
static void tcp_echoserver_send(struct tcp_pcb *tpcb, struct tcp_echoserver_struct *es);
static void tcp_echoserver_connection_close(struct tcp_pcb *tpcb, struct tcp_echoserver_struct *es);


/**
 * @brief  Initializes the tcp echo server
 * @param  None
 * @retval None
 */
void tcp_echoserver_init(void)
{
	/* create new tcp pcb */
	tcp_echoserver_pcb = tcp_new();

	if (tcp_echoserver_pcb != NULL)
	{
		err_t err;

		/* bind echo_pcb to port 7 (ECHO protocol) */
		err = tcp_bind(tcp_echoserver_pcb, IP_ADDR_ANY, SERVER_PORT);

		if (err == ERR_OK)
		{
			/* start tcp listening for echo_pcb */
			tcp_echoserver_pcb = tcp_listen(tcp_echoserver_pcb);

			/* initialize LwIP tcp_accept callback function */
			tcp_accept(tcp_echoserver_pcb, tcp_echoserver_accept);
		}
		else
		{
			/* deallocate the pcb */
			memp_free(MEMP_TCP_PCB, tcp_echoserver_pcb);
		}
	}
}

/**
 * @brief  This function is the implementation of tcp_accept LwIP callback
 * @param  arg: not used
 * @param  newpcb: pointer on tcp_pcb struct for the newly created tcp connection
 * @param  err: not used
 * @retval err_t: error status
 */
static err_t tcp_echoserver_accept(void *arg, struct tcp_pcb *newpcb, err_t err)
{
	err_t ret_err;
	struct tcp_echoserver_struct *es;

	LWIP_UNUSED_ARG(arg);
	LWIP_UNUSED_ARG(err);

	/* set priority for the newly accepted tcp connection newpcb */
	tcp_setprio(newpcb, TCP_PRIO_MIN);

	/* allocate structure es to maintain tcp connection informations */
	es = (struct tcp_echoserver_struct *)mem_malloc(sizeof(struct tcp_echoserver_struct));
	if (es != NULL)
	{
		es->state = ES_ACCEPTED;
		es->pcb = newpcb;
		es->retries = 0;
		es->p = NULL;

		/* pass newly allocated es structure as argument to newpcb */
		tcp_arg(newpcb, es);

		/* initialize lwip tcp_recv callback function for newpcb  */
		tcp_recv(newpcb, tcp_echoserver_recv);

		/* initialize lwip tcp_err callback function for newpcb  */
		tcp_err(newpcb, tcp_echoserver_error);

		/* initialize lwip tcp_poll callback function for newpcb */
		tcp_poll(newpcb, tcp_echoserver_poll, 0);

		ret_err = ERR_OK;
	}
	else
	{
		/*  close tcp connection */
		tcp_echoserver_connection_close(newpcb, es);
		/* return memory error */
		ret_err = ERR_MEM;
	}
	return ret_err;
}


#define DEBUG_OK {BSP_LED_On(LED2); BSP_LED_Off(LED3);}
#define DEBUG_BAD {BSP_LED_On(LED3); BSP_LED_Off(LED2);}

char *  parse_string(char * s, const unsigned int len){
	BSP_LED_Off(LED3);
	BSP_LED_Off(LED2);

#define str_robot_len 5 // robot
	static char str_robot[str_robot_len] = {"robot"};
	static char str_GO[2] = {"GO"};

	float drive1 = 0;
	float drive2 = 0;
	float instrument = 0;
	float kolonna=0;
	float rotation=0;
	float rezka=0;
	float magnit1=0;
	float magnit2=0;

	int velosity_delay = 1; //
	int steps_count = 10;

	int pos = -1;
	char * pch = NULL;

	pch = strtok(s, ":");
	//    printf("pch = %s\n", pch);
	  if (HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13)){
			  HAL_GPIO_WritePin(GPIOB, LD1_Pin, GPIO_PIN_SET);

			  HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_SET);
	  }


	if(pch != NULL) {
		  HAL_GPIO_WritePin(GPIOB, LD2_Pin, GPIO_PIN_SET);
		pos = memcmp(s, &str_robot, str_robot_len);
		if(pos==0){   // в начале "robot"
			pch = strtok(NULL, ":");   // следующая лексема GO
			//            printf("pch = %s\n", pch);

			pos = memcmp(pch, &str_GO, 2);
			if(pos==0){   // в начале "GO"
				pch = strtok(NULL, ";");   // число drive1
				//                printf("pch = %s\n", pch);
				if (pch != NULL) {
					drive1 = atof(pch);

					pch = strtok(NULL, ";");   // число drive2
					if (pch != NULL) {
						drive2 = atof(pch);

						pch = strtok(NULL, ";");   // число instrument
						if (pch != NULL) {
							instrument = atof(pch);

							pch = strtok(NULL, ";");   // число kolonna
								if (pch != NULL) {
									kolonna = atof(pch);
									pch = strtok(NULL, ";");   // число rotation
										if (pch != NULL) {
											rotation = atof(pch);
											pch = strtok(NULL, ";");   // число rezka
												if (pch != NULL) {
													rezka = atof(pch);
													pch = strtok(NULL, ";");   // число magnit1
														if (pch != NULL) {
															magnit1 = atof(pch);

															pch = strtok(NULL, ";");   // число magnit2
																if (pch != NULL) {
																	magnit2 = atof(pch);
/////////////////
																	///////////////////
																	DEBUG_OK
																	HAL_GPIO_WritePin(GPIOB, LD2_Pin, GPIO_PIN_RESET);
																	/*
																	 *  robot:Go drive1, drive2 instrument
																	 *
																	 *
																	 * */
																	if (drive1 > 10) {
																	//

																		HAL_GPIO_WritePin(GPIOF, DIR1_Pin, GPIO_PIN_SET);
																		for(int i=0; i<steps_count; i++){
																			HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_SET);
																			HAL_GPIO_WritePin(GPIOD, STEP1_Pin, GPIO_PIN_SET);
																			HAL_Delay(velosity_delay);
																			HAL_GPIO_WritePin(GPIOD, STEP1_Pin, GPIO_PIN_RESET);
																			HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_RESET);
																			HAL_Delay(velosity_delay);
																		}
																		//

																	} else if (drive1 < -10 ){
																	//	HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_SET);

																		HAL_GPIO_WritePin(GPIOF, DIR1_Pin, GPIO_PIN_RESET);
																		for(int i=0; i<steps_count; i++){
																			HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_SET);
																			HAL_GPIO_WritePin(GPIOD, STEP1_Pin, GPIO_PIN_SET);
																			HAL_Delay(velosity_delay);
																			HAL_GPIO_WritePin(GPIOD, STEP1_Pin, GPIO_PIN_RESET);
																			HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_RESET);
																			HAL_Delay(velosity_delay);
																		}
																	}else {
																			HAL_GPIO_WritePin(GPIOF, DIR1_Pin, GPIO_PIN_RESET);
																			HAL_GPIO_WritePin(GPIOD, STEP1_Pin, GPIO_PIN_RESET);
																	}

																	if (drive2 > 10) {


																		HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_SET);

																		HAL_GPIO_WritePin(GPIOE, DIR2_Pin, GPIO_PIN_SET);
																		for(int i=0; i<steps_count; i++){
																		HAL_GPIO_WritePin(GPIOD, STEP2_Pin, GPIO_PIN_SET);
																		HAL_Delay(velosity_delay);
																		HAL_GPIO_WritePin(GPIOD, STEP2_Pin, GPIO_PIN_RESET);
																		HAL_Delay(velosity_delay);
																		}

																		HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_RESET);

																	} else if (drive2 < -10){

																		HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_SET);

																		HAL_GPIO_WritePin(GPIOE, DIR2_Pin, GPIO_PIN_RESET);
																		for(int i=0; i<steps_count; i++){
																		HAL_GPIO_WritePin(GPIOD, STEP2_Pin, GPIO_PIN_SET);
																		HAL_Delay(velosity_delay);
																		HAL_GPIO_WritePin(GPIOD, STEP2_Pin, GPIO_PIN_RESET);
																		HAL_Delay(velosity_delay);
																		}
																		HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_RESET);

																	}else {
																		HAL_GPIO_WritePin(GPIOE, DIR2_Pin, GPIO_PIN_RESET);
																		  HAL_GPIO_WritePin(GPIOD, STEP2_Pin, GPIO_PIN_RESET);
																	}

																	if (instrument > 0.9) {

																	//	HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_SET);

																		HAL_GPIO_WritePin(GPIOD, DIR3_Pin, GPIO_PIN_SET);
																		for(int i=0; i<steps_count; i++){
																		HAL_GPIO_WritePin(GPIOD, STEP3_Pin, GPIO_PIN_SET);
																		HAL_Delay(velosity_delay);
																		HAL_GPIO_WritePin(GPIOD, STEP3_Pin, GPIO_PIN_RESET);
																		HAL_Delay(velosity_delay);
																		}

																	//	HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_RESET);

																	} else if (instrument < -0.9){

																	//	HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_SET);

																	    HAL_GPIO_WritePin(GPIOD, DIR3_Pin, GPIO_PIN_RESET);
																		for(int i=0; i<steps_count; i++){
																		HAL_GPIO_WritePin(GPIOD, STEP3_Pin, GPIO_PIN_SET);
																		HAL_Delay(velosity_delay);
																		HAL_GPIO_WritePin(GPIOD, STEP3_Pin, GPIO_PIN_RESET);
																		HAL_Delay(velosity_delay);
																		}
																	//	HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_RESET);

																	}else {
																		HAL_GPIO_WritePin(GPIOD, DIR3_Pin, GPIO_PIN_RESET);
																		HAL_GPIO_WritePin(GPIOD, STEP3_Pin, GPIO_PIN_RESET);
																	}
																	//rotation
																	if (rotation > 0.9) {

																		HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_SET);

																		HAL_GPIO_WritePin(GPIOE, DIR5_Pin, GPIO_PIN_SET);
																		for(int i=0; i<steps_count; i++){
																		HAL_GPIO_WritePin(GPIOE, STEP5_Pin, GPIO_PIN_SET);
																		HAL_Delay(velosity_delay);
																		HAL_GPIO_WritePin(GPIOE, STEP5_Pin, GPIO_PIN_RESET);
																		HAL_Delay(velosity_delay);
																		}


																		HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_RESET);

																	} else if (rotation < -0.9){

																		HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_SET);

																		for(int i=0; i<steps_count; i++){
																		HAL_GPIO_WritePin(GPIOE, STEP5_Pin, GPIO_PIN_SET);
																		HAL_Delay(velosity_delay);
																		HAL_GPIO_WritePin(GPIOE, STEP5_Pin, GPIO_PIN_RESET);
																		HAL_Delay(velosity_delay);
																		}
																		HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_RESET);

																	}else {
																		HAL_GPIO_WritePin(GPIOE, DIR5_Pin, GPIO_PIN_RESET);
																		HAL_GPIO_WritePin(GPIOE, STEP5_Pin, GPIO_PIN_RESET);
																	}
																	//rezka
																	if (rezka > 0.9) {

																		//HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_SET);

																		HAL_GPIO_WritePin(GPIOD, DIR4_Pin, GPIO_PIN_SET);
																		for(int i=0; i<steps_count; i++){
																		HAL_GPIO_WritePin(GPIOE, STEP4_Pin, GPIO_PIN_SET);
																		HAL_Delay(velosity_delay);
																		HAL_GPIO_WritePin(GPIOE, STEP4_Pin, GPIO_PIN_RESET);
																		HAL_Delay(velosity_delay);
																		}

																	//	HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_RESET);

																	} else if (rezka < -0.9){

																	//	HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_SET);

																		HAL_GPIO_WritePin(GPIOD, DIR4_Pin, GPIO_PIN_RESET);
																		for(int i=0; i<steps_count; i++){
																			HAL_GPIO_WritePin(GPIOE, STEP4_Pin, GPIO_PIN_SET);
																			HAL_Delay(velosity_delay);
																			HAL_GPIO_WritePin(GPIOE, STEP4_Pin, GPIO_PIN_RESET);
																			HAL_Delay(velosity_delay);
																		}
																	//	HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_RESET);

																	}else {
																		HAL_GPIO_WritePin(GPIOD, DIR4_Pin, GPIO_PIN_RESET);
																		HAL_GPIO_WritePin(GPIOE, STEP4_Pin, GPIO_PIN_RESET);
																	}

//// INVERSIA !!!!
																	if ( kolonna > 0.9) {
																		 HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_SET);
																		 HAL_GPIO_WritePin(GPIOE, PILLAR_ONOFF_Pin, GPIO_PIN_RESET);
																		 HAL_GPIO_WritePin(GPIOF, PILLAR_UPDOWN_Pin, GPIO_PIN_RESET);
																		 HAL_Delay(500);
																		 HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_RESET);

																	} else if ( kolonna < -0.9){
																		HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_SET);

																		 HAL_GPIO_WritePin(GPIOE, PILLAR_ONOFF_Pin, GPIO_PIN_RESET);
																		 HAL_GPIO_WritePin(GPIOF, PILLAR_UPDOWN_Pin, GPIO_PIN_SET);
																		 HAL_Delay(500);
																		 HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_RESET);

																	}else {
																		HAL_GPIO_WritePin(GPIOE, PILLAR_ONOFF_Pin, GPIO_PIN_SET);
																		HAL_GPIO_WritePin(GPIOF, PILLAR_UPDOWN_Pin, GPIO_PIN_SET);
																	}

																	if (magnit1 > 0) {
																		HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_SET);
																		HAL_GPIO_WritePin(GPIOE, MAGNET1_ONOFF_Pin, GPIO_PIN_RESET);
																	} else {
																		HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_RESET);
																		HAL_GPIO_WritePin(GPIOE, MAGNET1_ONOFF_Pin, GPIO_PIN_SET);
																	}

																	if (magnit2 > 0) {
																		HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_SET);
																		HAL_GPIO_WritePin(GPIOE, MAGNET2_ONOFF_Pin, GPIO_PIN_RESET);
																	} else {
																		HAL_GPIO_WritePin(GPIOB, LD3_Pin, GPIO_PIN_RESET);
																		HAL_GPIO_WritePin(GPIOE, MAGNET2_ONOFF_Pin, GPIO_PIN_SET);
																	}
																	//////////////////////





																	// run robot
																	char *buf;
																	buf = (char *) malloc(100);
																	sprintf(buf,"rcvd: %f; %f; %f; %f; %f; %f; %f; %f;\n", drive1, drive2, instrument, kolonna, rotation, rezka, magnit1, magnit2);
																	return buf;
																}
														}
												}
										}
								}
						}
					}
				}
			}
		}
	}
	DEBUG_BAD
	return NULL;
}





/**
 * @brief  This function is the implementation for tcp_recv LwIP callback
 * @param  arg: pointer on a argument for the tcp_pcb connection
 * @param  tpcb: pointer on the tcp_pcb connection
 * @param  pbuf: pointer on the received pbuf
 * @param  err: error information regarding the reveived pbuf
 * @retval err_t: error code
 */
static err_t tcp_echoserver_recv(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err)
{
	struct tcp_echoserver_struct *es;
	err_t ret_err;

	char str[50];
	char *buf;

	LWIP_ASSERT("arg != NULL",arg != NULL);

	es = (struct tcp_echoserver_struct *)arg;

	/* if we receive an empty tcp frame from client => close connection */
	if (p == NULL)
	{
		/* remote host closed connection */
		es->state = ES_CLOSING;
		if(es->p == NULL)
		{
			/* we're done sending, close connection */
			tcp_echoserver_connection_close(tpcb, es);
		}
		else
		{
			/* we're not done yet */
			/* acknowledge received packet */
			tcp_sent(tpcb, tcp_echoserver_sent);

			/* send remaining data*/
			//tcp_echoserver_send(tpcb, es);

			memcpy(str, p -> payload, p -> len);
			buf = parse_string(str, p->len);

			/*
			 * Отсылка данных не столько важна, но для отладки это хорошо
			 * */
			if(buf!=NULL){
				p -> payload = buf;
				p -> len = strlen(buf);
				es->p = p;

				tcp_echoserver_send(tpcb, es);
				free(buf);
			}


		}
		ret_err = ERR_OK;
	}
	/* else : a non empty frame was received from client but for some reason err != ERR_OK */
	else if(err != ERR_OK)
	{
		/* free received pbuf*/
		if (p != NULL)
		{
			es->p = NULL;
			pbuf_free(p);
		}
		ret_err = err;
	}
	else if(es->state == ES_ACCEPTED)
	{
		/* first data chunk in p->payload */
		es->state = ES_RECEIVED;

		/* store reference to incoming pbuf (chain) */
		es->p = p;

		/* initialize LwIP tcp_sent callback function */
		tcp_sent(tpcb, tcp_echoserver_sent);

		/* send back the received data (echo) */
		//tcp_echoserver_send(tpcb, es);

		memcpy(str, p -> payload, p -> len);
		buf = parse_string(str, p->len);

		/*
		 * Отсылка данных не столько важна, но для отладки это хорошо
		 * */
		if(buf!=NULL){
			p -> payload = buf;
			p -> len = strlen(buf);
			es->p = p;

			tcp_echoserver_send(tpcb, es);
			free(buf);
		}

		ret_err = ERR_OK;
	}
	else if (es->state == ES_RECEIVED)
	{
		/* more data received from client and previous data has been already sent*/
		if(es->p == NULL)
		{
			//			es->p = p;
			/* send back received data */
			//			tcp_echoserver_send(tpcb, es);

			memcpy(str, p -> payload, p -> len);
			buf = parse_string(str, p->len);

			/*
			 * Отсылка данных не столько важна, но для отладки это хорошо
			 * */
			if(buf!=NULL){
				p -> payload = buf;
				p -> len = strlen(buf);
				es->p = p;

				tcp_echoserver_send(tpcb, es);
				free(buf);
			}
		}
		else
		{
			struct pbuf *ptr;

			/* chain pbufs to the end of what we recv'ed previously  */
			ptr = es->p;
			pbuf_chain(ptr,p);
		}
		ret_err = ERR_OK;
	}
	else if(es->state == ES_CLOSING)
	{
		/* odd case, remote side closing twice, trash data */
		tcp_recved(tpcb, p->tot_len);
		es->p = NULL;
		pbuf_free(p);
		ret_err = ERR_OK;
	}
	else
	{
		/* unkown es->state, trash data  */
		tcp_recved(tpcb, p->tot_len);
		es->p = NULL;
		pbuf_free(p);
		ret_err = ERR_OK;
	}
	return ret_err;
}

/**
 * @brief  This function implements the tcp_err callback function (called
 *         when a fatal tcp_connection error occurs.
 * @param  arg: pointer on argument parameter
 * @param  err: not used
 * @retval None
 */
static void tcp_echoserver_error(void *arg, err_t err)
{
	struct tcp_echoserver_struct *es;

	LWIP_UNUSED_ARG(err);

	es = (struct tcp_echoserver_struct *)arg;
	if (es != NULL)
	{
		/*  free es structure */
		mem_free(es);
	}
}

/**
 * @brief  This function implements the tcp_poll LwIP callback function
 * @param  arg: pointer on argument passed to callback
 * @param  tpcb: pointer on the tcp_pcb for the current tcp connection
 * @retval err_t: error code
 */
static err_t tcp_echoserver_poll(void *arg, struct tcp_pcb *tpcb)
{
	err_t ret_err;
	struct tcp_echoserver_struct *es;

	es = (struct tcp_echoserver_struct *)arg;
	if (es != NULL)
	{
		if (es->p != NULL)
		{
			tcp_sent(tpcb, tcp_echoserver_sent);
			/* there is a remaining pbuf (chain) , try to send data */
			tcp_echoserver_send(tpcb, es);
		}
		else
		{
			/* no remaining pbuf (chain)  */
			if(es->state == ES_CLOSING)
			{
				/*  close tcp connection */
				tcp_echoserver_connection_close(tpcb, es);
			}
		}
		ret_err = ERR_OK;
	}
	else
	{
		/* nothing to be done */
		tcp_abort(tpcb);
		ret_err = ERR_ABRT;
	}
	return ret_err;
}

/**
 * @brief  This function implements the tcp_sent LwIP callback (called when ACK
 *         is received from remote host for sent data)
 * @param  None
 * @retval None
 */
static err_t tcp_echoserver_sent(void *arg, struct tcp_pcb *tpcb, u16_t len)
{
	struct tcp_echoserver_struct *es;

	LWIP_UNUSED_ARG(len);

	es = (struct tcp_echoserver_struct *)arg;
	es->retries = 0;

	if(es->p != NULL)
	{
		/* still got pbufs to send */
		tcp_sent(tpcb, tcp_echoserver_sent);
		tcp_echoserver_send(tpcb, es);
	}
	else
	{
		/* if no more data to send and client closed connection*/
		if(es->state == ES_CLOSING)
			tcp_echoserver_connection_close(tpcb, es);
	}
	return ERR_OK;
}


/**
 * @brief  This function is used to send data for tcp connection
 * @param  tpcb: pointer on the tcp_pcb connection
 * @param  es: pointer on echo_state structure
 * @retval None
 */
static void tcp_echoserver_send(struct tcp_pcb *tpcb, struct tcp_echoserver_struct *es)
{
	struct pbuf *ptr;
	err_t wr_err = ERR_OK;

	while ((wr_err == ERR_OK) &&
			(es->p != NULL) &&
			(es->p->len <= tcp_sndbuf(tpcb)))
	{

		/* get pointer on pbuf from es structure */
		ptr = es->p;

		/* enqueue data for transmission */
		wr_err = tcp_write(tpcb, ptr->payload, ptr->len, 1);

		if (wr_err == ERR_OK)
		{
			u16_t plen;
			u8_t freed;

			plen = ptr->len;

			/* continue with next pbuf in chain (if any) */
			es->p = ptr->next;

			if(es->p != NULL)
			{
				/* increment reference count for es->p */
				pbuf_ref(es->p);
			}

			/* chop first pbuf from chain */
			do
			{
				/* try hard to free pbuf */
				freed = pbuf_free(ptr);
			}
			while(freed == 0);
			/* we can read more data now */
			tcp_recved(tpcb, plen);
		}
		else if(wr_err == ERR_MEM)
		{
			/* we are low on memory, try later / harder, defer to poll */
			es->p = ptr;
		}
		else
		{
			/* other problem ?? */
		}
	}
}

/**
 * @brief  This functions closes the tcp connection
 * @param  tcp_pcb: pointer on the tcp connection
 * @param  es: pointer on echo_state structure
 * @retval None
 */
static void tcp_echoserver_connection_close(struct tcp_pcb *tpcb, struct tcp_echoserver_struct *es)
{

	/* remove all callbacks */
	tcp_arg(tpcb, NULL);
	tcp_sent(tpcb, NULL);
	tcp_recv(tpcb, NULL);
	tcp_err(tpcb, NULL);
	tcp_poll(tpcb, NULL, 0);

	/* delete es structure */
	if (es != NULL)
	{
		mem_free(es);
	}

	/* close tcp connection */
	tcp_close(tpcb);
}

#endif /* LWIP_TCP */




//// Cравнивает две стороки одинаковой
//int isequal(char *buf, char *subbuf)
//     {
//      int i = 0;
//      while( buf[i] == subbuf[i]) i++;
//      //  i--;
//      // if (i f) ) i=0;
//      return (i) ; // отлажено
//     }
