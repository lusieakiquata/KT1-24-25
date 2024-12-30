// Import the functions you need from the SDKs you need
import { initializeApp } from "firebase/app";
import { getAnalytics } from "firebase/analytics";
// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
// For Firebase JS SDK v7.20.0 and later, measurementId is optional
const firebaseConfig = {
  apiKey: "AIzaSyCguAoNfRl4DCl7crkcvVR2qeiPUg1sXKg",
  authDomain: "kt1--25.firebaseapp.com",
  databaseURL: "https://kt1--25-default-rtdb.firebaseio.com",
  projectId: "kt1--25",
  storageBucket: "kt1--25.firebasestorage.app",
  messagingSenderId: "164109132232",
  appId: "1:164109132232:web:5f02301027a2114a8be0fd",
  measurementId: "G-WPYVN8D8RS"
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);
const analytics = getAnalytics(app);
const database = firebase.database();

function reset() {
  database.ref('hoadon1').set({
    bapcai: 0
  });
}
