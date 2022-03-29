#include <pthread.h>

int pthread_create(pthread_t *thread, const pthread_attr_t *attr,void *(*start_routine)(void *), void *arg);
/*
 * 첫번째 아규먼트인 thread 는 쓰레드가 성공적으로 생성되었을때 생성된 쓰레드를 식별하기 위해서 사용되는 쓰레드 식별자이다. 
 * 두번째 아규먼트인 attr 은 쓰레드 특성을 지정하기 위해서 사용하며, 기본 쓰레드 특성을 이용하고자 할경우에 NULL 을 사용한다. 
 * 세번째 아규먼트인 start_routine는 분기시켜서 실행할 쓰레드 함수이며
 * 네번째 아규먼는인 arg는 쓰레드 함수의 인자이다.
 * 성공적으로 생성될경우 0을 리턴한다.
 * */
 
int pthread_join(pthread_t th, void **thread_return);
/*
 * 첫번째 아규먼트 th는 기다릴(join)할 쓰레드 식별자이며, 
 * 두번째 아규먼트 thread_return은 쓰레드의 리턴(return) 값이다. 
 * thread_return 이 NULL 이 아닐경우 해더 포인터로 쓰레드 리턴 값을 받아올수 있다.
 * */
 
int pthread_detach(pthread_t th);
/*
 * detach 는 main 쓰레드에서 pthread_create 를 이용해 생성된 쓰레드를 분리시킨다.
 * 이 함수는 식별번호th인 쓰레드를 detach 시키는데, detach 되었을경우 해당 쓰레드가 종료될경우 pthread_join 을 호출하지 않더라도 즉시 모든 자원이 해제(free) 된다.
* */
void pthread_exit(void *retval);
/*
 * pthread_exit 는 현재 실행중인 쓰레드를 종료시키고자 할때 사용한다. 
 * 만약 pthread_cleanup_push 가 정의되어 있다면, pthread_exit 가 호출될경우 cleanup handler 가 호출된다. 
 * 보통 이 cleanup handler 은 메모리를 정리하는 등의 일을 하게 된다.
 * */

void pthrad_cleanup_push(void (*routine) (void *), void *arg);
/*
 * cleanup handlers 를 인스톨하기 위해서 사용된다. 
 * pthread_exit(3)가 호출되어서 쓰레드가 종료될때 pthread_cleanup_push 에 의해서 인스톨된 함수가 호출된다. 
 * routine이 쓰레드가 종료될때 호출되는 함수이다. arg는 아규먼트이다.
 * cleanup handlers 는 주로 자원을 되돌려주거나, mutex 잠금등의 해제를 위한 용도로 사용된다.
 * */

void pthread_cleanup_pop(int execute);
/*
 * 만약 execute 가 0 이라면, pthread_cleanup_push 에 의해 인스톨된 cleanup handler 를 (실행시키지 않고)삭제만 시킨다.
 * 0 이 아닌 숫자라면 cleanup handler 을 실행시키고 삭제 된다.
 * 그리고 pthread_cleanup_push 와 pthread_cleanup_pop 은 반드시 같은 함수내의 같은 레벨의 블럭에서 한쌍으로 사용해야 한다.
 * */

pthread_t pthread_self(void);
/*
 * pthread_self를 호출하는 현재 쓰래드의 쓰레드식별자를 되돌려준다.
 * */
 
 int pthread_mutex_init(pthread_mutex_t * mutex, const pthread_mutex_attr *attr); 
/*
 * mutex 는 여러개의 쓰레드가 공유하는 데이타를 보호하기 위해서 사용되는 도구로써, 보호하고자 하는 데이타를 다루는 코드영역을 단지 한번에 하나의 쓰레드만 실행가능 하도록 하는 방법으로 공유되는 데이타를 보호한다. 
 * pthread_mutex_init 는 mutex 객체를 초기화 시키기 위해서 사용한다. 
 * 첫번째 인자로 주어지는 mutex 객체 mutex를 초기화시키며 
 * 두번째 인자인 attr 를 이용해서 mutex 특성을 변경할수 있다.
 * 기본 mutex 특성을 이용하기 원한다면 NULL 을 사용하면 된다.
 * mutex 특성(종류) 에는 "fast", "recurisev", "error checking" 의 종류가 있으며, 기본으로 "fast" 가 사용된다.
 * */
 
int pthread_mutex_destroy(pthread_mutex_t *mutex);
/*
 * 인자로 주어진 뮤텍스 객체 mutex 를 제거하기 위해서 사용된다.
 * */

int pthread_mutex_lock(pthread_mutex_t *mutex);
/*
 * pthread_mutex_lock 는 critical section 에 들어가기 위해서 mutex lock 을 요청한다.
 * */

int pthread_mutex_unlock(pthread_mutex_t *mutex); 
/*
 * critical section 에서의 모든 작업을 마치고 mutex lock 을 돌려주기 위해서 사용한다.
 * */

int pthread_cond_init(pthread_cond_t *cond, const pthread_cond_attr *attr);
/*
 * pthread_cond_init는 조견변수 (condition variable)cond를 초기화하기 위해서 사용한다.
 * attr 를 이용해서 조건변수의 특성을 변경할수 있으며, NULL 을 줄경우 기본특성으로 초기화된다.
 * 조건변수 cond는 상수 PTHREAD_COND_INITIALIZER 을 이용해서도 초기화 할수 있다. 
 * */

int pthread_cond_signal(pthread_cond_t *cond);
/*
 * 조건변수 cond에 시그날을 보낸다.
 * */

int pthread_cond_broadcast(pthread_cond_t *cond);
/*
 * 조건변수 cond에서 기다리는(wait) 모든 쓰레드에게 신호를 보내서, 깨운다는 점을 제외하고는 pthread_cond_signal과 동일하게 작동한다.
 * */

int pthread_cond_wait(pthread_cond_t cond, pthread_mutex_t *mutex); 
/*
 * 조건변수 cond를 통해서 신호가 전달될때까지 블럭된다. 
 * */

int pthread_cond_timedwait(pthread_cont_t *cond, pthread_mutex_t *mutex, const struct timespec *abstime);
/*
 * pthread_cond_wait와 동일하다.
 * 시간체크가 가능해서 abstime시간동안 신호가 도착하지 않는다면 error 를 발생하면서 리턴한다.
 * 이때 리턴값은 ETIMEDOUT 이다. errno 가 세팅되는게 아닌, 리턴값으로 에러가 넘어오는것에 주의해야 한다.
 * */
 
 int pthread_cond_destroy(pthread_cond_t *cond);
 /*
  * pthread_cond_init를 통해서 생성한 조건변수cond에 대한 자원을 해제한다.
  * destroy 함수를 호출하기 전에 어떤 쓰레드도 cond에서의 시그널을 기다리지 않는걸 확인해야 한다.
  * 만약 cond 시그널을 기다리는 쓰레드가 존재한다면 이 함수는 실패하고 EBUSY 를 리턴한다.
  * */
 
int pthread_attr_init(pthread_attr_t *attr);
/*
 * pthread_attr_init는 thread attribute 객체인 attr을 디폴트 값으로 초기화 시킨다.
 * 성공할경우 0을 돌려주고 실패할경우 -1 을 되돌려준다.
 * */

int pthread_attr_destroy(pthread_attr_t *attr);
/*
 * pthread_attr_init에 의해 생성된 thread attribute 객체인 attr을 제거한다. 제거된 attr 을 다시 사용하기 위해서는 pthread_attr_init를 이용해서 다시 초기화 해주어야 한다.
*/
int pthread_attr_getscope(const pthread_attr_t *attr, int *scope);
/*
  * 쓰레드가 어떤 영역(scope)에서 다루어지고 있는지를 얻어오기 위해서 사용된다. PTHREAD_SCOPE_SYSTEM과 PTHREAD_SCOPE_PROCESS 의 2가지 영역중에 선택할수 있다. SYSTEM 영역 쓰레드는 user 모드 쓰레드라고 불리우며, PROCESS 쓰레드는 커널모드 쓰레드라고 불리운다.
*/

int pthread_attr_setscope(pthread_attr_t *attr, int scope);
/*
 * 쓰레드가 어떤 영역(scope)에서 작동하게 할것인지 결정하기 위해서 사용한다. 
*/

int pthread_attr_getdetachstate(pthread_attr_t *attr, int detachstate);
/*
 * 쓰레드가 join 가능한 상태(PTHREAD_CREATE_JOINABLE) 인지 detached 상태인지 (PTHREAD_CREATE_DETACHED) 인지를 알아낸다. 알아낸 값은 아규먼트 detachstate에 저장된다.
*/
int  pthread_attr_setdetachstate(pthread_attr_t *attr, int detachstate);
/*
 * 쓰레드의 상태를 PTHREAD_CREATE_JOINABLE 혹은 PTHREAD_CREATE_DETACHED 상태로 변경시키기 위해서 사용된다.
*/

#include <signal.h>

int pthread_sigmask(int how, const sigset_t *newmask, sigset_t *oldmask);
/*
 * 특정 쓰레드만 시그널을 받도록 하고 싶을 때 이 함수를 이용하면 된다.
*/
int pthread_kill(pthread_t thread, int signo);
/*
 * 쓰레드 식별번호 thread로 signo번호의 시그널을 전달한다.
*/
int sigwait(const sigset_t *set, int *sig);
/*
 * 시그널 전달을 동기적으로 기다린다.
*/
