/**
  * \file PnlWzskLlvCamera.js
  * web client functionality for panel PnlWzskLlvCamera
  * \author Catherine Johnson
  * \date created: 18 Oct 2020
  * \date modified: 18 Oct 2020
  */

// IP cust --- IBEGIN
function refreshLive(mask) {
	if (!contcontdoc) return;

	var cvs = contcontdoc.getElementById("cvs");
	var cvsctx = cvs.getContext("2d");

	var wCvs = cvs.width;
	var hCvs = cvs.height;

	var scale_old = doc.scale;

	var whbase = 0;

	var w, h;
	var x0, y0;

	var ix, ix2;

	// - scaling
	var d = doc.imgdat.data;

	if ( (mask.indexOf("red") != -1) && (mask.indexOf("green") != -1) && (mask.indexOf("blue") != -1) ) {
		whbase = Math.round(Math.sqrt(doc.red.length/12));
		if (12*whbase*whbase != doc.red.length) return;

	} else if (mask.indexOf("gray") != -1) {
		whbase = Math.round(Math.sqrt(doc.gray.length/12));
		if (12*whbase*whbase != doc.gray.length) return;
	};

	w = 4 * whbase;
	h = 3 * whbase;

	doc.scale = Math.floor(wCvs / w);
	if (Math.floor(hCvs / h) < doc.scale) doc.scale = Math.floor(hCvs / h);

	if (doc.scale != scale_old) for (var i = 0; i < 4*hCvs*wCvs; i++) d[i] = 255;

	x0 = wCvs/2 - (doc.scale * w) / 2;
	y0 = hCvs/2 - (doc.scale * h) / 2;

	// - canvas
	if ( (mask.indexOf("red") != -1) && (mask.indexOf("green") != -1) && (mask.indexOf("blue") != -1) ) {
		for (var i = 0; i < h; i++) {
			for (var j = 0; j < w; j++) {
				ix = i*w + j;
				ix2 = 4 * ((y0 + doc.scale*i)*wCvs + x0 + doc.scale*j);

				for (var k = 0; k < doc.scale; k++) {
					for (var l = 0; l < doc.scale; l++) {
						d[ix2] = doc.red[ix];
						d[ix2+1] = doc.green[ix];
						d[ix2+2] = doc.blue[ix];
						d[ix2+3] = 255;

						ix2 += 4;
					};

					ix2 += 4 * (wCvs - doc.scale);
				};
			};
		};

	} else if (mask.indexOf("gray") != -1) {
		for (var i = 0; i < h; i++) {
			for (var j = 0; j < w; j++) {
				ix = i*w + j;
				ix2 = 4 * ((y0 + doc.scale*i)*wCvs + x0 + doc.scale*j);

				for (var k = 0; k < doc.scale; k++) {
					for (var l = 0; l < doc.scale; l++) {

						d[ix2] = doc.gray[ix];
						d[ix2+1] = doc.gray[ix];
						d[ix2+2] = doc.gray[ix];
						d[ix2+3] = 255;

						ix2 += 4;
					};

					ix2 += 4 * (wCvs - doc.scale);
				};
			};
		};
	};

	cvsctx.putImageData(doc.imgdat, 0, 0);
};
// IP cust --- IEND

// --- expand state management
function minimize() {
	// change container heights
	getCrdwnd().changeHeight("Camera", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Camera_side").setAttribute("height", "30");
	doc.getElementById("Camera_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Camera_side").src = "./PnlWzskLlvCamera_aside.html";
	doc.getElementById("Camera_cont").src = "./PnlWzskLlvCamera_a.html";
};

function regularize() {
	// change content (container heights in refreshBD)
	doc.getElementById("Camera_side").src = "./PnlWzskLlvCamera_bside.html";
	doc.getElementById("Camera_cont").src = "./PnlWzskLlvCamera_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Camera_side").contentDocument;
	contdoc = doc.getElementById("Camera_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzskLlvCamera", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Camera_side").contentDocument;
	contdoc = doc.getElementById("Camera_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Camera_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Camera_cont").contentDocument;

	// IP initBD --- RBEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWzskLlvCamera", "Cpt"));
	initCpt(contcontdoc, "CptMde", retrieveTi(srcdoc, "TagWzskLlvCamera", "CptMde"));
	refreshPup(contcontdoc, srcdoc, "PupMde", "", "FeedFPupMde", retrieveCi(srcdoc, "ContIacWzskLlvCamera", "numFPupMde"), true, false);
	initCpt(contcontdoc, "CptAex", retrieveTi(srcdoc, "TagWzskLlvCamera", "CptAex"));
	initCpt(contcontdoc, "CptFcs", retrieveTi(srcdoc, "TagWzskLlvCamera", "CptFcs"));
	initCpt(contcontdoc, "CptExt", retrieveTi(srcdoc, "TagWzskLlvCamera", "CptExt"));

	var cvs = contcontdoc.getElementById("cvs");

	doc.scale = 1.0;

	doc.imgdat = cvs.getContext("2d").createImageData(cvs.width, cvs.height);
	// IP initBD --- REND

	refreshBD(bNotD);
};

function init() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvCamera", "srefIxWzskVExpstate");

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

	var height = 622; // full cont height

	// IP refreshBD.vars --- BEGIN
	var ButClaimActive = (retrieveSi(srcdoc, "StatShrWzskLlvCamera", "ButClaimActive") == "true");

	var ButPlayActive = (retrieveSi(srcdoc, "StatShrWzskLlvCamera", "ButPlayActive") == "true");
	var ButStopActive = (retrieveSi(srcdoc, "StatShrWzskLlvCamera", "ButStopActive") == "true");

	var ChkAexActive = (retrieveSi(srcdoc, "StatShrWzskLlvCamera", "ChkAexActive") == "true");

	var SldExtAvail = (retrieveSi(srcdoc, "StatShrWzskLlvCamera", "SldExtAvail") == "true");
	var SldExtActive = (retrieveSi(srcdoc, "StatShrWzskLlvCamera", "SldExtActive") == "true");

	var SldFcsActive = (retrieveSi(srcdoc, "StatShrWzskLlvCamera", "SldFcsActive") == "true");

	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshButicon(hdrdoc, "ButClaim", "icon/claim", ButClaimActive, retrieveCi(srcdoc, "ContInfWzskLlvCamera", "ButClaimOn") == "true");
	contcontdoc.getElementById("PupMde").value = retrieveCi(srcdoc, "ContIacWzskLlvCamera", "numFPupMde");

	refreshButicon(contcontdoc, "ButPlay", "iconwzsk/play", ButPlayActive, false);
	refreshButicon(contcontdoc, "ButStop", "iconwzsk/stop", ButStopActive, false);

	refreshChk(contcontdoc, "ChkAex", (retrieveCi(srcdoc, "ContIacWzskLlvCamera", "ChkAex") == "true"), ChkAexActive);

	height -= setCtlAvail(contcontdoc, "Ext", SldExtAvail, 25);
	if (SldExtAvail) {
		refreshSld(contcontdoc, "SldExt", true, true, parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvCamera", "SldExtMin")), parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvCamera", "SldExtMax")), parseFloat(retrieveCi(srcdoc, "ContIacWzskLlvCamera", "SldExt")), SldExtActive, false);

	};

	refreshSld(contcontdoc, "SldFcs", true, false, parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvCamera", "SldFcsMin")), parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvCamera", "SldFcsMax")), parseFloat(retrieveCi(srcdoc, "ContIacWzskLlvCamera", "SldFcs")), SldFcsActive, false);

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Camera", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Camera_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Camera_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Camera_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvCamera", "srefIxWzskVExpstate");

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
	srcdoc = doc.getElementById("Camera_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzskInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskLlvCameraDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleChkChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);
	var checked;

	elem.setAttribute("class", "chkmod");

	if (elem.checked == true) checked = "true"; else checked = "false";
	setCi(srcdoc, "ContIacWzskLlvCamera", ctlsref, checked);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskLlvCameraData", scrJref, "ContIacWzskLlvCamera");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWzskLlvCamera", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskLlvCameraData", scrJref, "ContIacWzskLlvCamera");
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

	if (shr) oldVal = parseFloat(retrieveCi(srcdoc, "ContIacWzskLlvCamera", ctlsref));
	else oldVal = parseFloat(_doc.getElementById(ctlsref + "Val").value);
	min = parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvCamera", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvCamera", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvCamera", ctlsref + "Rast"));

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
		setCi(srcdoc, "ContIacWzskLlvCamera", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzskLlvCameraData", scrJref, "ContIacWzskLlvCamera");
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

	if (shr) oldVal = parseFloat(retrieveCi(srcdoc, "ContIacWzskLlvCamera", ctlsref));
	else oldVal = parseFloat(_doc.getElementById(ctlsref + "Val").value);
	min = parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvCamera", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvCamera", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvCamera", ctlsref + "Rast"));

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
		setCi(srcdoc, "ContIacWzskLlvCamera", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzskLlvCameraData", scrJref, "ContIacWzskLlvCamera");
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

	min = parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvCamera", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvCamera", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvCamera", ctlsref + "Rast"));
	else rast = 0.0;

	pos = getSldPosFromEvtx(true, evt.clientX);

	if (log) val = getSldLogvalFromPos(min, max, rast, pos);
	else val = getSldValFromPos(min, max, rast, pos);

	setSldPos(_doc, ctlsref, true, pos);
	setSldVal(_doc, ctlsref, val, true, true);

	if (shr) setCi(srcdoc, "ContIacWzskLlvCamera", ctlsref, "" + val);
	else window["handle" + ctlsref + "Change"](val);
};

function handleSldMup(_doc, ctlsref, shr) {
	_doc.getElementById("td" + ctlsref).onmousemove = null;
	_doc.getElementById("td" + ctlsref).onmouseup = null;

	if (shr) {
		var str = serializeDpchAppData(srcdoc, "DpchAppWzskLlvCameraData", scrJref, "ContIacWzskLlvCamera");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

function handleSldValKey(_doc, ctlsref, shr, log, _rast, evt) {
	var elem = _doc.getElementById(ctlsref + "Val");

	var pos, val;

	var min, max, rast;

	elem.setAttribute("class", "txfxsmod");

	if (evt.keyCode == 13) {
		min = parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvCamera", ctlsref + "Min"));
		max = parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvCamera", ctlsref + "Max"));

		if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvCamera", ctlsref + "Rast"));
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
			setCi(srcdoc, "ContIacWzskLlvCamera", ctlsref, "" + val);

			var str = serializeDpchAppData(srcdoc, "DpchAppWzskLlvCameraData", scrJref, "ContIacWzskLlvCamera");
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

	min = parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvCamera", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvCamera", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrWzskLlvCamera", ctlsref + "Rast"));
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
		setCi(srcdoc, "ContIacWzskLlvCamera", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzskLlvCameraData", scrJref, "ContIacWzskLlvCamera");
		sendReq(str, doc, handleDpchAppDataDoReply);

	} else {
	window["handle" + ctlsref + "Change"](val);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWzskLlvCameraData", "ContIacWzskLlvCamera", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWzskLlvCameraData", "ContInfWzskLlvCamera", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWzskLlvCameraData", "FeedFPupMde", srcdoc)) mask.push("feedFPupMde");
	if (updateSrcblock(dom, "DpchEngWzskLlvCameraData", "StatShrWzskLlvCamera", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskLlvCameraData", "TagWzskLlvCamera", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzskLlvCameraData") {
		var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvCamera", "srefIxWzskVExpstate");

		var mask = mergeDpchEngData(dom);

		if (mask.indexOf("statshr") != -1) {
			var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvCamera", "srefIxWzskVExpstate");

			if (srefIxWzskVExpstate != oldSrefIxWzskVExpstate) {
				if (srefIxWzskVExpstate == "mind") minimize();
				else if (srefIxWzskVExpstate == "regd") regularize();
			} else {
				refresh();
			};

		} else {
			refresh();
		};
	} else if (dpch == "DpchEngWzskLlvCameraLive") {
		handleDpchEngWzskLlvCameraLive(dom);
	};
};

function handleDpchEngWzskLlvCameraLive(dom) {
	// IP handleDpchEngWzskLlvCameraLive --- IBEGIN
	var mask = [];

	var resnode;

	// gray
	resnode = getNode(dom, "//wzsk:DpchEngWzskLlvCameraLive/wzsk:gray");
	if (resnode) {
		doc.gray = parseUtinyintvec(resnode.textContent);
		mask.push("gray");
	};

	// RGB
	resnode = getNode(dom, "//wzsk:DpchEngWzskLlvCameraLive/wzsk:red");
	if (resnode) {
		doc.red = parseUtinyintvec(resnode.textContent);
		mask.push("red");
	};

	resnode = getNode(dom, "//wzsk:DpchEngWzskLlvCameraLive/wzsk:green");
	if (resnode) {
		doc.green = parseUtinyintvec(resnode.textContent);
		mask.push("green");
	};

	resnode = getNode(dom, "//wzsk:DpchEngWzskLlvCameraLive/wzsk:blue");
	if (resnode) {
		doc.blue = parseUtinyintvec(resnode.textContent);
		mask.push("blue");
	};

	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvCamera", "srefIxWzskVExpstate");
	if (srefIxWzskVExpstate == "regd") refreshLive(mask);
	// IP handleDpchEngWzskLlvCameraLive --- IEND
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wzsk:*");
		if (blk) {
			if (blk.nodeName == "DpchEngWzskLlvCameraData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Camera");
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

			} else if (blk.nodeName == "DpchEngWzskLlvCameraData") {
				var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvCamera", "srefIxWzskVExpstate");

				var mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLlvCamera", "srefIxWzskVExpstate");

					if (srefIxWzskVExpstate != oldSrefIxWzskVExpstate) {
						if (srefIxWzskVExpstate == "mind") minimize();
						else if (srefIxWzskVExpstate == "regd") regularize();
					} else {
						refresh();
					};

				} else {
					refresh();
				};
			} else if (blk.nodeName == "DpchEngWzskLlvCameraLive") {
				handleDpchEngWzskLlvCameraLive(dom);
			};
		};
	};
};



