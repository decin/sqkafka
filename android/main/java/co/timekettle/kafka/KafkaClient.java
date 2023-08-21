package co.timekettle.kafka;

import android.util.Log;

public class KafkaClient {
   static {
      System.loadLibrary("rdkafka");
      System.loadLibrary("rdkafka++");
      System.loadLibrary("sqkafka");
   }

   private static final String TAG = "KafkaClient";

   private static final String OnlineBrokers = "x.x.x.x:1000,x.x.x.y:1000,x.x.x.z:1000";
   private static final String LocalBrokers = "192.168.2.124:9092";

   private static final String DefaultBrokers = OnlineBrokers;
   private static final String DefaultTopic   = "timekettle.trace.app";

   public KafkaClient() {
      this(DefaultBrokers);
   }

   public KafkaClient(String brokers) {
      KafkaOpen(brokers, 3000);
   }

   public void send(String topic, String msg) {
      long sendTime = System.currentTimeMillis();
      msg = msg.replace("}", ",\"sendTime\":"+ sendTime + "}");
      String err = KafkaSend(topic, msg);
      if (err != null) Log.e(TAG, "send: " + err);
   }

   public void send(String msg) {
      this.send(DefaultTopic, msg);
   }

   @Override
   protected void finalize() throws Throwable {
      super.finalize();
      KafkaClose();
   }

   private long mNativeKafka; // 关联 c++ 指针
   public native long KafkaOpen(String brokers, int timeout);
   public native String KafkaSend(String topic, String msg);
   public native void KafkaClose();

}