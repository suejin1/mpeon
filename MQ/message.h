// //calc_data.h

// #ifndef message_H
// #define message_H
// using namespace std;

// pthread_mutex_t msgmutex = PTHREAD_MUTEX_INITIALIZER;
// queue<string> msgq;



// struct message
// {
// public:
 
//   static void* msgreceiver(void *arg);
//   static void* msgtransmitter(void *arg);

// };


// void* message::msgreceiver(void *arg)
// {
//     long qsize;
//     string nextmsg;

//     while(true)
//     {
//       if(msgq.empty())
//       {
//         usleep(10000); // sleep 0.01 sec before trying again
//         continue;
//       }

//       // we end up here because there was something in the msg queue
//       pthread_mutex_lock(&msgmutex);
//       qsize=msgq.size();
//       if(qsize > 5)cout << "Queue size: " << qsize << endl;
//       nextmsg=msgq.front(); // get next message in queue
//       msgq.pop(); // remove it from the queue
//       pthread_mutex_unlock(&msgmutex);

//       cout << "Processing value " << nextmsg << endl;
//       usleep(2000000);
//     }
//     pthread_exit((void *)0);
// } // msgreceiver()



// void* message::msgtransmitter(void *arg)
// {
//     string nextmsg;

//     while(true)
//     {
//       cin >> nextmsg;
//       pthread_mutex_lock(&msgmutex);
//       msgq.push(nextmsg); // push message onto the queue
//       pthread_mutex_unlock(&msgmutex);
//     }
//     pthread_exit((void *)0);
// } // msgtransmitter()

// #endif