

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
  database.ref('RST').on('value', (snapshot) => {
      const t = snapshot.val();
			if(t == 1) reset();
	 });	 
  //gia cap nhap//
function updatePrices() {
  // Danh sách các hóa đơn
  const hoadons = ['hoadon1', 'hoadon2', 'hoadon3', 'hoadon4', 'hoadon5'];

  // Danh sách các mặt hàng với vị trí hàng tương ứng trong bảng
  const items = [
    { key: 'giacarot', row: 1 },
    { key: 'giakhoaitay', row: 2 },
    { key: 'giabi', row: 3 },
    { key: 'giabapcai', row: 4 },
  ];

  // Duyệt qua từng mặt hàng
  items.forEach((item) => {
    database.ref(`gia/${item.key}`).on('value', (snapshot) => {
      const gia = snapshot.val() || '0';

      // Cập nhật giá trị vào từng hóa đơn
      hoadons.forEach((hoadon) => {
        document.getElementById(hoadon).rows[item.row].cells[2].innerText = gia;
      });
    });
  });
}

// Gọi hàm để cập nhật giá
updatePrices();

 // document.getElementById('hoadon1').rows[1].cells[2].innerText = '3';
 
 
  database.ref('hoadon1/tongtien').on('value', (snapshot) => {
      const tong = snapshot.val();
	document.getElementById('tt1').innerText = "tổng: "+tong +"đ" || '0';
	 });
	 
	database.ref('hoadon2/tongtien').on('value', (snapshot) => {
      const tong = snapshot.val();
	document.getElementById('tt2').innerText = "tổng: "+tong +"đ" || '0';
	 });
database.ref('hoadon3/tongtien').on('value', (snapshot) => {
      const tong = snapshot.val();
	document.getElementById('tt3').innerText = "tổng: "+tong +"đ" || '0';
	 });
	 database.ref('hoadon4/tongtien').on('value', (snapshot) => {
      const tong = snapshot.val();
	document.getElementById('tt4').innerText = "tổng: "+tong +"đ" || '0';
	 });
	 
database.ref('hoadon5/tongtien').on('value', (snapshot) => {
      const tong = snapshot.val();
	document.getElementById('tt5').innerText = "tổng: "+tong +"đ" || '0';
	 });
	 

	 
	 
//khoi luong hd1
function updateKLData() {
  // Danh sách các hóa đơn
  const hoadons = ['hoadon1', 'hoadon2', 'hoadon3', 'hoadon4', 'hoadon5'];

  // Danh sách các mặt hàng trong từng hóa đơn
  const items = ['carot', 'khoaitay', 'bi', 'bapcai'];

  // Duyệt qua từng hóa đơn
  hoadons.forEach((hoadon, hoadonIndex) => {
    // Duyệt qua từng mặt hàng
    items.forEach((item, itemIndex) => {
      database.ref(`${hoadon}/kl/${item}`).on('value', (snapshot) => {
        const value = snapshot.val();
        // Cập nhật giá trị trong bảng
        document.getElementById(hoadon).rows[itemIndex + 1].cells[1].innerText = value;
      });
    });
  });
}

// Gọi hàm để cập nhật dữ liệu
updateKLData();

//tien kl//
updateTableData();

function updateTableData() {
  // Danh sách các hóa đơn
  const hoadons = ['hoadon1', 'hoadon2', 'hoadon3', 'hoadon4', 'hoadon5'];

  // Danh sách các trường trong từng hóa đơn
  const fields = ['tiencr', 'tienkt', 'tienbi', 'tienbc'];

  // Duyệt qua từng hóa đơn
  hoadons.forEach((hoadon, hoadonIndex) => {
    // Duyệt qua từng trường trong hóa đơn
    fields.forEach((field, fieldIndex) => {
      database.ref(`${hoadon}/tien/${field}`).on('value', (snapshot) => {
        const value = snapshot.val();
        // Cập nhật giá trị trong bảng
        document.getElementById(hoadon).rows[fieldIndex + 1].cells[3].innerText = value;
      });
    });
  });
};

// Gọi hàm để cập nhật dữ liệu

	
function reset() {
  const rs = {
    bapcai: 0,
    bi: 0,
    carot: 0,
    khoaitay: 0,
  };

  const rst = {
    tienbc: 0,
    tienbi: 0,
    tiencr: 0,
    tienkt: 0,
  };

  // Reset giá trị 'kl' trong các hoadon
  for (let i = 1; i <= 5; i++) {
    database.ref(`hoadon${i}/kl`).set(rs);
    database.ref(`hoadon${i}/tien`).set(rst);
		// Reset cả giá trị tiền
  }
  database.ref(`hoadon${i}/tongtien`).set(0);
	database.ref('RST').set(0);

  console.log('Reset thành công!');
};