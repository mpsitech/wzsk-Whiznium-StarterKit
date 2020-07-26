/**
  * \file PnlWzskLiv3DView.js
  * web client functionality for panel PnlWzskLiv3DView
  * \author Catherine Johnson
  * \date created: 23 Jul 2020
  * \date modified: 23 Jul 2020
  */

// IP cust --- IBEGIN
function refreshLive(mask) {
	if (!contcontdoc) return;

	var scale = 75.0;

	if ( (mask.indexOf("x") != -1) && (mask.indexOf("y") != -1) && (mask.indexOf("z") != -1) ) {
		doc.scene = new THREE.Scene();
		doc.camera = new THREE.PerspectiveCamera(60, 690 / 500, 0.1, 10);
		doc.material = new THREE.PointsMaterial({color:0x00ff00,size:0.03});

		doc.vertices = [];
		for (var i = 0; i < doc.x.length; i++) doc.vertices.push(scale * doc.x[i], -scale * doc.z[i], scale * doc.y[i]);

		doc.geometry = new THREE.BufferGeometry();
		doc.geometry.setAttribute('position', new THREE.Float32BufferAttribute(doc.vertices, 3));

		doc.points = new THREE.Points(doc.geometry, doc.material);
		doc.scene.add(doc.points);

		doc.camera.position.z = 5;

		doc.renderer.render(doc.scene, doc.camera);
	};
};

function animate() {
	if (!doc.points) return;

	doc.points.rotation.y += 0.01;
	doc.renderer.render(doc.scene, doc.camera);

	requestAnimationFrame(animate);
};

// IP cust --- IEND

// --- expand state management
function minimize() {
	// change container heights
	getCrdwnd().changeHeight("3DView", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("3DView_side").setAttribute("height", "30");
	doc.getElementById("3DView_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("3DView_side").src = "./PnlWzskLiv3DView_aside.html";
	doc.getElementById("3DView_cont").src = "./PnlWzskLiv3DView_a.html";
};

function regularize() {
	// change content (container heights in refreshBD)
	doc.getElementById("3DView_side").src = "./PnlWzskLiv3DView_bside.html";
	doc.getElementById("3DView_cont").src = "./PnlWzskLiv3DView_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("3DView_side").contentDocument;
	contdoc = doc.getElementById("3DView_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzskLiv3DView", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("3DView_side").contentDocument;
	contdoc = doc.getElementById("3DView_cont").contentDocument;
	hdrdoc = contdoc.getElementById("3DView_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("3DView_cont").contentDocument;

	// IP initBD --- RBEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWzskLiv3DView", "Cpt"));
	initCpt(contcontdoc, "HdgAcq", retrieveTi(srcdoc, "TagWzskLiv3DView", "HdgAcq"));
	initCpt(contcontdoc, "CptAst", retrieveTi(srcdoc, "TagWzskLiv3DView", "CptAst"));
	initCpt(contcontdoc, "CptAoa", retrieveTi(srcdoc, "TagWzskLiv3DView", "CptAoa"));
	initBut(contcontdoc, "ButAst", retrieveTi(srcdoc, "TagWzskLiv3DView", "ButAst"));

	doc.renderer = new THREE.WebGLRenderer();
	doc.renderer.setSize(690, 500);
	contcontdoc.getElementById("tdTre").appendChild(doc.renderer.domElement);
	// IP initBD --- REND

	refreshBD(bNotD);
};

function init() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLiv3DView", "srefIxWzskVExpstate");

	if (srefIxWzskVExpstate == "mind") {
		initA();
	} else if (srefIxWzskVExpstate == "regd") {
		initBD(true);
	} else if (srefIxWzskVExpstate == "detd") {
		initBD(false);
	};
};

function refreshA() {
};

function refreshBD(bNotD) {
	if (!contcontdoc) return;

	var height = 642; // full cont height

	// IP refreshBD.vars --- BEGIN
	var ButClaimActive = (retrieveSi(srcdoc, "StatShrWzskLiv3DView", "ButClaimActive") == "true");

	var ButPlayActive = (retrieveSi(srcdoc, "StatShrWzskLiv3DView", "ButPlayActive") == "true");
	var ButStopActive = (retrieveSi(srcdoc, "StatShrWzskLiv3DView", "ButStopActive") == "true");

	var TxtAoaAvail = (retrieveSi(srcdoc, "StatShrWzskLiv3DView", "TxtAoaAvail") == "true");

	var ButAstActive = (retrieveSi(srcdoc, "StatShrWzskLiv3DView", "ButAstActive") == "true");

	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshButicon(hdrdoc, "ButClaim", "icon/claim", ButClaimActive, retrieveCi(srcdoc, "ContInfWzskLiv3DView", "ButClaimOn") == "true");

	refreshButicon(contcontdoc, "ButPlay", "iconwzsk/play", ButPlayActive, false);
	refreshButicon(contcontdoc, "ButStop", "iconwzsk/stop", ButStopActive, false);

	refreshTxt(contcontdoc, "TxtAst", retrieveCi(srcdoc, "ContInfWzskLiv3DView", "TxtAst"));

	height -= setCtlAvail(contcontdoc, "Aoa", TxtAoaAvail, 25);
	if (TxtAoaAvail) {
		refreshTxt(contcontdoc, "TxtAoa", retrieveCi(srcdoc, "ContInfWzskLiv3DView", "TxtAoa"));

	};

	refreshBut(contcontdoc, "ButAst", ButAstActive, false);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("3DView", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("3DView_side").setAttribute("height", "" + (height+31));
	doc.getElementById("3DView_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("3DView_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLiv3DView", "srefIxWzskVExpstate");

	if (srefIxWzskVExpstate == "mind") {
		refreshA();
	} else if (srefIxWzskVExpstate == "regd") {
		refreshBD(true);
	} else if (srefIxWzskVExpstate == "detd") {
		refreshBD(false);
	};
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("3DView_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzskInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

function handleSldTreHChange(val) {
	// IP handleSldTreHChange --- INSERT
};

function handleSldTreVChange(val) {
	// IP handleSldTreVChange --- INSERT
};

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
if (ctlsref == "ButAst") {
	doc.renderer.clear();
	animate();

	return;
};

	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskLiv3DViewDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleSldJpleftMov(_doc, ctlsref) {
	if (_doc.getElementById("td" + ctlsref).onmousemove == null) {
		_doc.getElementById(ctlsref + "Jpleftl").setAttribute("class", "sldlhlt");
	};
};

function handleSldJpleftMou(_doc, ctlsref) {
	_doc.getElementById(ctlsref + "Jpleftl").setAttribute("class", "sldl");
};

function handleSldJpleftClick(_doc, ctlsref, shr, log, _rast, evt) {
	var pos, oldVal, val;

	var min, max, rast;

	if (shr) oldVal = parseFloat(retrieveCi(srcdoc, "ContIacWzskLiv3DView", ctlsref));
	else oldVal = parseFloat(_doc.getElementById(ctlsref + "Val").value);
	min = parseFloat(retrieveSi(srcdoc, "StatShrWzskLiv3DView", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrWzskLiv3DView", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrWzskLiv3DView", ctlsref + "Rast"));

	if (_rast) {
		if (log) val = oldVal / rast;
		else val = oldVal - rast;

		if (val < min) val = min;
		if (val > max) val = max;

	} else {
		pos = getSldPosFromEvtx(true, evt.clientX);
		val = getSldValFromPos(min, max, rast, pos);
	};

	pos = getSldPosFromVal(min, max, val);

	setSldPos(_doc, ctlsref, true, pos);
	setSldVal(_doc, ctlsref, val, true, true);

	if (shr) {
		setCi(srcdoc, "ContIacWzskLiv3DView", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzskLiv3DViewData", scrJref, "ContIacWzskLiv3DView");
		sendReq(str, doc, handleDpchAppDataDoReply);

	} else {
		window["handle" + ctlsref + "Change"](val);
	};
};

function handleSldJprightMov(_doc, ctlsref) {
	if (_doc.getElementById("td" + ctlsref).onmousemove == null) {
		_doc.getElementById(ctlsref + "Jprightl").setAttribute("class", "sldlhlt");
	};
};

function handleSldJprightMou(_doc, ctlsref) {
	_doc.getElementById(ctlsref + "Jprightl").setAttribute("class", "sldl");
};

function handleSldJprightClick(_doc, ctlsref, shr, log, _rast, evt) {
	var pos, oldVal, val;

	var min, max, rast;

	if (shr) oldVal = parseFloat(retrieveCi(srcdoc, "ContIacWzskLiv3DView", ctlsref));
	else oldVal = parseFloat(_doc.getElementById(ctlsref + "Val").value);
	min = parseFloat(retrieveSi(srcdoc, "StatShrWzskLiv3DView", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrWzskLiv3DView", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrWzskLiv3DView", ctlsref + "Rast"));

	if (_rast) {
		if (log) val = oldVal * rast;
		else val = oldVal + rast;

		if (val < min) val = min;
		if (val > max) val = max;

	} else {
		pos = getSldPosFromEvtx(true, evt.clientX);
		val = getSldValFromPos(min, max, rast, pos);
	};

	pos = getSldPosFromVal(min, max, val);

	setSldPos(_doc, ctlsref, true, pos);
	setSldVal(_doc, ctlsref, val, true, true);

	if (shr) {
		setCi(srcdoc, "ContIacWzskLiv3DView", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzskLiv3DViewData", scrJref, "ContIacWzskLiv3DView");
		sendReq(str, doc, handleDpchAppDataDoReply);

	} else {
		window["handle" + ctlsref + "Change"](val);
	};
};

function handleSldMov(_doc, ctlsref) {
	_doc.getElementById(ctlsref + "Bar").setAttribute("class", "sldlhlt");
};

function handleSldMou(_doc, ctlsref) {
	if (_doc.getElementById("td" + ctlsref).onmousemove == null) {
		_doc.getElementById(ctlsref + "Bar").setAttribute("class", "sldl");
	};
};

function handleSldMdn(_doc, ctlsref) {
	_doc.getElementById("td" + ctlsref).setAttribute("onmousemove", "handle" + ctlsref + "Move(event)");
	_doc.getElementById("td" + ctlsref).setAttribute("onmouseup", "handle" + ctlsref + "Mup(event)");
};

function handleSldMove(_doc, ctlsref, shr, log, _rast, evt) {
	var pos, val;

	var min, max, rast;

	min = parseFloat(retrieveSi(srcdoc, "StatShrWzskLiv3DView", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrWzskLiv3DView", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrWzskLiv3DView", ctlsref + "Rast"));
	else rast = 0.0;

	pos = getSldPosFromEvtx(true, evt.clientX);

	if (log) val = getSldLogvalFromPos(min, max, rast, pos);
	else val = getSldValFromPos(min, max, rast, pos);

	setSldPos(_doc, ctlsref, true, pos);
	setSldVal(_doc, ctlsref, val, true, true);

	if (shr) setCi(srcdoc, "ContIacWzskLiv3DView", ctlsref, "" + val);
	else window["handle" + ctlsref + "Change"](val);
};

function handleSldMup(_doc, ctlsref, shr) {
	_doc.getElementById("td" + ctlsref).onmousemove = null;
	_doc.getElementById("td" + ctlsref).onmouseup = null;

	if (shr) {
		var str = serializeDpchAppData(srcdoc, "DpchAppWzskLiv3DViewData", scrJref, "ContIacWzskLiv3DView");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

function handleSldValKey(_doc, ctlsref, shr, log, _rast, evt) {
	var elem = _doc.getElementById(ctlsref + "Val");

	var pos, val;

	var min, max, rast;

	elem.setAttribute("class", "txfxsmod");

	if (evt.keyCode == 13) {
		min = parseFloat(retrieveSi(srcdoc, "StatShrWzskLiv3DView", ctlsref + "Min"));
		max = parseFloat(retrieveSi(srcdoc, "StatShrWzskLiv3DView", ctlsref + "Max"));

		if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrWzskLiv3DView", ctlsref + "Rast"));
		else rast = 0.0;

		val = parseFloat(elem.value);
		if (isNaN(val)) val = 0.0;

		if (log) {
			val = alignSldLogval(min, max, rast, val);
			pos = getSldPosFromLogval(min, max, val);
		} else {
			val = alignSldVal(min, max, rast, val);
			pos = getSldPosFromVal(min, max, val);
		};

		setSldPos(_doc, ctlsref, true, pos);
		setSldVal(_doc, ctlsref, val, true, true);

		if (shr) {
			setCi(srcdoc, "ContIacWzskLiv3DView", ctlsref, "" + val);

			var str = serializeDpchAppData(srcdoc, "DpchAppWzskLiv3DViewData", scrJref, "ContIacWzskLiv3DView");
			sendReq(str, doc, handleDpchAppDataDoReply);

		} else {
			window["handle" + ctlsref + "Change"](val);
		};

		return false;
	};

	return true;
};

function handleSldValChange(_doc, ctlsref, shr, log, _rast) {
	var elem = _doc.getElementById(ctlsref + "Val");

	var pos, val;

	var min, max, rast;

	elem.setAttribute("class", "txfxsmod");

	min = parseFloat(retrieveSi(srcdoc, "StatShrWzskLiv3DView", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrWzskLiv3DView", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrWzskLiv3DView", ctlsref + "Rast"));
	else rast = 0.0;

	val = parseFloat(elem.value);
	if (isNaN(val)) val = 0.0;

	if (log) {
		val = alignSldLogval(min, max, rast, val);
		pos = getSldPosFromLogval(min, max, val);
	} else {
		val = alignSldVal(min, max, rast, val);
		pos = getSldPosFromVal(min, max, val);
	};

	setSldPos(_doc, ctlsref, true, pos);
	setSldVal(_doc, ctlsref, val, true, true);

	if (shr) {
		setCi(srcdoc, "ContIacWzskLiv3DView", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzskLiv3DViewData", scrJref, "ContIacWzskLiv3DView");
		sendReq(str, doc, handleDpchAppDataDoReply);

	} else {
	window["handle" + ctlsref + "Change"](val);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWzskLiv3DViewData", "ContInfWzskLiv3DView", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWzskLiv3DViewData", "StatShrWzskLiv3DView", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskLiv3DViewData", "TagWzskLiv3DView", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzskLiv3DViewData") {
		var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLiv3DView", "srefIxWzskVExpstate");

		var mask = mergeDpchEngData(dom);

		if (mask.indexOf("statshr") != -1) {
			var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLiv3DView", "srefIxWzskVExpstate");

			if (srefIxWzskVExpstate != oldSrefIxWzskVExpstate) {
				if (srefIxWzskVExpstate == "mind") minimize();
				else if (srefIxWzskVExpstate == "regd") regularize();
			} else {
				refresh();
			};

		} else {
			refresh();
		};
	} else if (dpch == "DpchEngWzskLiv3DViewLive") {
		handleDpchEngWzskLiv3DViewLive(dom);
	};
};

function handleDpchEngWzskLiv3DViewLive(dom) {
	// IP handleDpchEngWzskLiv3DViewLive --- IBEGIN
	var mask = [];

	var resnode;

	resnode = getNode(dom, "//wzsk:DpchEngWzskLiv3DViewLive/wzsk:rNotL");
	if (resnode) {
		doc.rNotL = parseBooleanvec(resnode.textContent);
		mask.push("rNotL");
	};

	resnode = getNode(dom, "//wzsk:DpchEngWzskLiv3DViewLive/wzsk:x");
	if (resnode) {
		doc.x = parseFloatvec(resnode.textContent);
		mask.push("x");
	};

	resnode = getNode(dom, "//wzsk:DpchEngWzskLiv3DViewLive/wzsk:y");
	if (resnode) {
		doc.y = parseFloatvec(resnode.textContent);
		mask.push("y");
	};

	resnode = getNode(dom, "//wzsk:DpchEngWzskLiv3DViewLive/wzsk:z");
	if (resnode) {
		doc.z = parseFloatvec(resnode.textContent);
		mask.push("z");
	};

	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLiv3DView", "srefIxWzskVExpstate");
	if (srefIxWzskVExpstate == "regd") refreshLive(mask);
	// IP handleDpchEngWzskLiv3DViewLive --- IEND
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wzsk:*");
		if (blk) {
			if (blk.nodeName == "DpchEngWzskLiv3DViewData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("3DView");
			};
		};
	};
};

function handleDpchAppDataDoReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		// check dispatch type
		blk = retrieveBlock(dom, "//wzsk:*");

		if (blk) {
			if (blk.nodeName == "DpchEngWzskConfirm") {
				// do nothing

			} else if (blk.nodeName == "DpchEngWzskLiv3DViewData") {
				var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLiv3DView", "srefIxWzskVExpstate");

				var mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLiv3DView", "srefIxWzskVExpstate");

					if (srefIxWzskVExpstate != oldSrefIxWzskVExpstate) {
						if (srefIxWzskVExpstate == "mind") minimize();
						else if (srefIxWzskVExpstate == "regd") regularize();
					} else {
						refresh();
					};

				} else {
					refresh();
				};
			};
		};
	};
};



