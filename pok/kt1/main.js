

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
firebase.initializeApp(firebaseConfig);
    const database = firebase.database();



  /*database.ref('gia/giabapcai').on('value', (snapshot) => {
    const gia = snapshot.val();
    document.getElementById('hoadon1').cows[1].cells[2].innerText = gia || 'Không có dữ liệu';
  });}*/
  //gia cap nhap//
  database.ref('gia/giacarot').on('value', (snapshot) => {
      const gia = snapshot.val();
      document.getElementById('hoadon1').rows[1].cells[2].innerText = gia || '0';
      document.getElementById('hoadon2').rows[1].cells[2].innerText = gia || '0';
      document.getElementById('hoadon3').rows[1].cells[2].innerText = gia || '0';
      document.getElementById('hoadon4').rows[1].cells[2].innerText = gia || '0';
      document.getElementById('hoadon5').rows[1].cells[2].innerText = gia || '0';
    });
    database.ref('gia/giakhoaitay').on('value', (snapshot) => {
      const gia = snapshot.val();
      document.getElementById('hoadon1').rows[2].cells[2].innerText = gia || '0';
      document.getElementById('hoadon2').rows[2].cells[2].innerText = gia || '0';
      document.getElementById('hoadon3').rows[2].cells[2].innerText = gia || '0';
      document.getElementById('hoadon4').rows[2].cells[2].innerText = gia || '0';
      document.getElementById('hoadon5').rows[2].cells[2].innerText = gia || '0';
    });
    database.ref('gia/giabi').on('value', (snapshot) => {
      const gia = snapshot.val();
      document.getElementById('hoadon1').rows[3].cells[2].innerText = gia || '0';
      document.getElementById('hoadon2').rows[3].cells[2].innerText = gia || '0';
      document.getElementById('hoadon3').rows[3].cells[2].innerText = gia || '0';
      document.getElementById('hoadon4').rows[3].cells[2].innerText = gia || '0';
      document.getElementById('hoadon5').rows[3].cells[2].innerText = gia || '0';
    });
    database.ref('gia/giabapcai').on('value', (snapshot) => {
      const gia = snapshot.val();
      document.getElementById('hoadon1').rows[4].cells[2].innerText = gia || '0';
      document.getElementById('hoadon2').rows[4].cells[2].innerText = gia || '0';
      document.getElementById('hoadon3').rows[4].cells[2].innerText = gia || '0';
      document.getElementById('hoadon4').rows[4].cells[2].innerText = gia || '0';
      document.getElementById('hoadon5').rows[4].cells[2].innerText = gia || '0';
    });
 // document.getElementById('hoadon1').rows[1].cells[2].innerText = '3';


