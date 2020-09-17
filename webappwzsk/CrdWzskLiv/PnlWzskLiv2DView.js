/**
  * \file PnlWzskLiv2DView.js
  * web client functionality for panel PnlWzskLiv2DView
  * \author Catherine Johnson
  * \date created: 16 Sep 2020
  * \date modified: 16 Sep 2020
  */

// IP cust --- IBEGIN
function refreshRoi(traceNotCorner) {
	if (!contcontdoc) return;

	var blksref;

	if (!traceNotCorner) blksref = "ContIacWzskLiv2DViewCorner";
	else blksref = "ContIacWzskLiv2DViewTrace";

	var Ax = retrieveCi(srcdoc, blksref, "roiAx");
	var Ay = retrieveCi(srcdoc, blksref, "roiAy");
	var Bx = retrieveCi(srcdoc, blksref, "roiBx");
	var By = retrieveCi(srcdoc, blksref, "roiBy");
	var Cx = retrieveCi(srcdoc, blksref, "roiCx");
	var Cy = retrieveCi(srcdoc, blksref, "roiCy");
	var Dx = retrieveCi(srcdoc, blksref, "roiDx");
	var Dy = retrieveCi(srcdoc, blksref, "roiDy");

	var d = "M " + Ax + "," + Ay + " L " + Bx + "," + By + " L " + Cx + "," + Cy + " L " + Dx + "," + Dy + " L " + Ax + "," + Ay;

	if (!traceNotCorner) {
		imgdoc.getElementById("roiCornerLine").setAttribute("d", d);

		imgdoc.getElementById("roiCornerA").setAttribute("cx", Ax);
		imgdoc.getElementById("roiCornerA").setAttribute("cy", Ay);
		imgdoc.getElementById("roiCornerB").setAttribute("cx", Bx);
		imgdoc.getElementById("roiCornerB").setAttribute("cy", By);
		imgdoc.getElementById("roiCornerC").setAttribute("cx", Cx);
		imgdoc.getElementById("roiCornerC").setAttribute("cy", Cy);
		imgdoc.getElementById("roiCornerD").setAttribute("cx", Dx);
		imgdoc.getElementById("roiCornerD").setAttribute("cy", Dy);

	} else {
		imgdoc.getElementById("roiTraceLineL").setAttribute("d", d);
		imgdoc.getElementById("roiTraceLineR").setAttribute("d", d);

		imgdoc.getElementById("roiTraceA").setAttribute("cx", Ax);
		imgdoc.getElementById("roiTraceA").setAttribute("cy", Ay);
		imgdoc.getElementById("roiTraceB").setAttribute("cx", Bx);
		imgdoc.getElementById("roiTraceB").setAttribute("cy", By);
		imgdoc.getElementById("roiTraceC").setAttribute("cx", Cx);
		imgdoc.getElementById("roiTraceC").setAttribute("cy", Cy);
		imgdoc.getElementById("roiTraceD").setAttribute("cx", Dx);
		imgdoc.getElementById("roiTraceD").setAttribute("cy", Dy);
	};
};

function refreshLive(mask) {
	if (!contcontdoc) return;

	var cvs = imgdoc.getElementById("cvs");
	var cvsctx = cvs.getContext("2d");

	var wCvs = cvs.width;
	var hCvs = cvs.height;

	var scaler = imgdoc.getElementById("scaler");
	var corner = imgdoc.getElementById("corner");
	var traceL = imgdoc.getElementById("traceL");
	var traceR = imgdoc.getElementById("traceR");

	var scale_old = doc.scale;

	var whbase = 0;

	var w, h;
	var x0, y0;

	var ix, ix2;

	var circle;
	var cx, cy;

	// - ROI initialization
	if (imgdoc.getElementById("roiCornerLine").getAttribute("stroke") == "none") {
		imgdoc.getElementById("roiCornerLine").setAttribute("stroke", "blue");

		refreshRoi(false);
		refreshRoi(true);
	};

	// - scaling
	var d = doc.imgdat.data;

	if ( (mask.indexOf("red") != -1) && (mask.indexOf("green") != -1) && (mask.indexOf("blue") != -1) ) {
		whbase = Math.round(Math.sqrt(doc.red.length/12));
		if (12*whbase*whbase != doc.red.length) return;

	} else if (mask.indexOf("gray") != -1) {
		whbase = Math.round(Math.sqrt(doc.gray.length/12));
		if (12*whbase*whbase != doc.gray.length) return;
	};

	if (whbase != 0) {
		w = 4 * whbase;
		h = 3 * whbase;

		doc.scale = Math.floor(wCvs / w);
		if (Math.floor(hCvs / h) < doc.scale) doc.scale = Math.floor(hCvs / h);

		if (doc.scale != scale_old) {
			for (var i = 0; i < 4*hCvs*wCvs; i++) d[i] = 255;

			// re-scale SVG; flagging frame size is 1024x768
			if ((1024%w) == 0) doc.scale_svg = doc.scale / (1024/w);
			else doc.scale_svg = 1.0 * doc.scale / (Math.floor(1024.0/w) + 2);

			scaler.setAttribute("transform", "scale(" + doc.scale_svg + " " + doc.scale_svg + ")");
		};

		x0 = wCvs/2 - (doc.scale * w) / 2;
		y0 = hCvs/2 - (doc.scale * h) / 2;
	};

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

	if ( (mask.indexOf("red") != -1) || (mask.indexOf("gray") != -1) ) cvsctx.putImageData(doc.imgdat, 0, 0);

	// - corner
	if ( (mask.indexOf("xCorner") != -1) && (mask.indexOf("yCorner") != -1) ) {
		clearElem(corner);

		for (var i = 0; i < doc.xCorner.length; i++) {
			cx = doc.xCorner[i]; 
			cy = doc.yCorner[i];

			circle = contdoc.createElementNS("http://www.w3.org/2000/svg", "svg:circle");
			circle.setAttribute("cx", "" + cx);
			circle.setAttribute("cy", "" + cy);
			circle.setAttribute("r", "2");
			circle.setAttribute("stroke-width", "0");
			circle.setAttribute("fill", "blue");

			corner.appendChild(circle);
		};
	};

	// - trace left
	if ( (mask.indexOf("xTraceL") != -1) && (mask.indexOf("yTraceL") != -1) ) {
		clearElem(traceL);

		for (var i = 0; i < doc.xTraceL.length; i++) {
			cx = doc.xTraceL[i]; // flagging frame size is 1024x768
			cy = doc.yTraceL[i];

			circle = contdoc.createElementNS("http://www.w3.org/2000/svg", "svg:circle");
			circle.setAttribute("cx", "" + cx);
			circle.setAttribute("cy", "" + cy);
			circle.setAttribute("r", "2");
			circle.setAttribute("stroke-width", "0");
			circle.setAttribute("fill", "red");

			traceL.appendChild(circle);
		};
	};

	// - trace right
	if ( (mask.indexOf("xTraceR") != -1) && (mask.indexOf("yTraceR") != -1) ) {
		clearElem(traceR);

		for (var i = 0; i < doc.xTraceR.length; i++) {
			cx = doc.xTraceR[i]; // flagging frame size is 1024x768
			cy = doc.yTraceR[i];

			circle = contdoc.createElementNS("http://www.w3.org/2000/svg", "svg:circle");
			circle.setAttribute("cx", "" + cx);
			circle.setAttribute("cy", "" + cy);
			circle.setAttribute("r", "2");
			circle.setAttribute("stroke-width", "0");
			circle.setAttribute("fill", "green");

			traceR.appendChild(circle);
		};
	};
};

function handleRoiMov(_doc, traceNotCorner, abcd) {
	var ctlsref = ((traceNotCorner) ? "roiTrace" : "roiCorner");
	ctlsref += abcd;

	_doc.getElementById(ctlsref).setAttribute("r", "10");
};

function handleRoiMou(_doc, traceNotCorner, abcd) {
	var ctlsref = ((traceNotCorner) ? "roiTrace" : "roiCorner");
	ctlsref += abcd;

	if (_doc.getElementById("divSvg").onmousemove == null) {
		_doc.getElementById(ctlsref).setAttribute("r", "6");
	};
};

function handleRoiMdn(_doc, traceNotCorner, abcd) {
	var ctlsref = ((traceNotCorner) ? "RoiTrace" : "RoiCorner");
	ctlsref += abcd;

	_doc.getElementById("divSvg").setAttribute("onmousemove", "handle" + ctlsref + "Move(event)");
	_doc.getElementById("divSvg").setAttribute("onmouseup", "handle" + ctlsref + "Mup(event)");
};

function handleRoiMove(_doc, traceNotCorner, abcd, evt) {
	var blksref = ((traceNotCorner) ? "ContIacWzskLiv2DViewTrace" : "ContIacWzskLiv2DViewCorner");

	var ctlsref = ((traceNotCorner) ? "roiTrace" : "roiCorner");
	ctlsref += abcd;

	var x = (evt.x - 345.5) / doc.scale_svg;
	var y = (evt.y - 192.5) / doc.scale_svg;

	setCi(srcdoc, blksref, "roi" + abcd + "x", "" + x);
	setCi(srcdoc, blksref, "roi" + abcd + "y", "" + y);

	refreshRoi(traceNotCorner);
};

function handleRoiMup(_doc, traceNotCorner, abcd) {
	var blksref = ((traceNotCorner) ? "ContIacWzskLiv2DViewTrace" : "ContIacWzskLiv2DViewCorner");

	_doc.getElementById("divSvg").onmousemove = null;
	_doc.getElementById("divSvg").onmouseup = null;

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskLiv2DViewAlign", scrJref, blksref);
	sendReq(str, doc, handleDpchAppDataDoReply);
};
// IP cust --- IEND

// --- expand state management
function minimize() {
	// change container heights
	getCrdwnd().changeHeight("2DView", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("2DView_side").setAttribute("height", "30");
	doc.getElementById("2DView_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("2DView_side").src = "./PnlWzskLiv2DView_aside.html";
	doc.getElementById("2DView_cont").src = "./PnlWzskLiv2DView_a.html";
};

function regularize() {
	// change content (container heights in refreshBD)
	doc.getElementById("2DView_side").src = "./PnlWzskLiv2DView_bside.html";
	doc.getElementById("2DView_cont").src = "./PnlWzskLiv2DView_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("2DView_side").contentDocument;
	contdoc = doc.getElementById("2DView_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzskLiv2DView", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("2DView_side").contentDocument;
	contdoc = doc.getElementById("2DView_cont").contentDocument;
	hdrdoc = contdoc.getElementById("2DView_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("2DView_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWzskLiv2DView", "Cpt"));
	initCpt(contcontdoc, "CptPvm", retrieveTi(srcdoc, "TagWzskLiv2DView", "CptPvm"));
	refreshPup(contcontdoc, srcdoc, "PupPvm", "", "FeedFPupPvm", retrieveCi(srcdoc, "ContIacWzskLiv2DView", "numFPupPvm"), true, false);
	initCpt(contcontdoc, "CptAex", retrieveTi(srcdoc, "TagWzskLiv2DView", "CptAex"));
	initCpt(contcontdoc, "CptExt", retrieveTi(srcdoc, "TagWzskLiv2DView", "CptExt"));
	initCpt(contcontdoc, "CptFcs", retrieveTi(srcdoc, "TagWzskLiv2DView", "CptFcs"));
	initCpt(contcontdoc, "CptOaf", retrieveTi(srcdoc, "TagWzskLiv2DView", "CptOaf"));
	initBut(contcontdoc, "ButSts", retrieveTi(srcdoc, "TagWzskLiv2DView", "ButSts"));
	initCpt(contcontdoc, "HdgTtb", retrieveTi(srcdoc, "TagWzskLiv2DView", "HdgTtb"));
	initBut(contcontdoc, "ButTcc", retrieveTi(srcdoc, "TagWzskLiv2DView", "ButTcc"));
	initBut(contcontdoc, "ButTcw", retrieveTi(srcdoc, "TagWzskLiv2DView", "ButTcw"));
	initCpt(contcontdoc, "HdgLor", retrieveTi(srcdoc, "TagWzskLiv2DView", "HdgLor"));
	initBut(contcontdoc, "ButLle", retrieveTi(srcdoc, "TagWzskLiv2DView", "ButLle"));
	initBut(contcontdoc, "ButLri", retrieveTi(srcdoc, "TagWzskLiv2DView", "ButLri"));
	initCpt(contcontdoc, "CptLlo", retrieveTi(srcdoc, "TagWzskLiv2DView", "CptLlo"));
	initCpt(contcontdoc, "CptLuo", retrieveTi(srcdoc, "TagWzskLiv2DView", "CptLuo"));
	initCpt(contcontdoc, "CptLmd", retrieveTi(srcdoc, "TagWzskLiv2DView", "CptLmd"));
	initCpt(contcontdoc, "CptLgl", retrieveTi(srcdoc, "TagWzskLiv2DView", "CptLgl"));
	initCpt(contcontdoc, "CptLro", retrieveTi(srcdoc, "TagWzskLiv2DView", "CptLro"));
	initBut(contcontdoc, "ButLtr", retrieveTi(srcdoc, "TagWzskLiv2DView", "ButLtr"));
	initBut(contcontdoc, "ButLcl", retrieveTi(srcdoc, "TagWzskLiv2DView", "ButLcl"));
	initCpt(contcontdoc, "HdgPos", retrieveTi(srcdoc, "TagWzskLiv2DView", "HdgPos"));
	initCpt(contcontdoc, "CptPnt", retrieveTi(srcdoc, "TagWzskLiv2DView", "CptPnt"));
	initCpt(contcontdoc, "CptPro", retrieveTi(srcdoc, "TagWzskLiv2DView", "CptPro"));
	initBut(contcontdoc, "ButPic", retrieveTi(srcdoc, "TagWzskLiv2DView", "ButPic"));
	initBut(contcontdoc, "ButPcl", retrieveTi(srcdoc, "TagWzskLiv2DView", "ButPcl"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLiv2DView", "srefIxWzskVExpstate");

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

	var height = 1004; // full cont height

	// IP refreshBD.vars --- BEGIN
	var ButClaimActive = (retrieveSi(srcdoc, "StatShrWzskLiv2DView", "ButClaimActive") == "true");

	var ButPlayActive = (retrieveSi(srcdoc, "StatShrWzskLiv2DView", "ButPlayActive") == "true");
	var ButStopActive = (retrieveSi(srcdoc, "StatShrWzskLiv2DView", "ButStopActive") == "true");

	var ChkAexActive = (retrieveSi(srcdoc, "StatShrWzskLiv2DView", "ChkAexActive") == "true");

	var SldExtAvail = (retrieveSi(srcdoc, "StatShrWzskLiv2DView", "SldExtAvail") == "true");
	var SldExtActive = (retrieveSi(srcdoc, "StatShrWzskLiv2DView", "SldExtActive") == "true");

	var SldFcsActive = (retrieveSi(srcdoc, "StatShrWzskLiv2DView", "SldFcsActive") == "true");

	var TxtOafAvail = (retrieveSi(srcdoc, "StatShrWzskLiv2DView", "TxtOafAvail") == "true");

	var ButStsActive = (retrieveSi(srcdoc, "StatShrWzskLiv2DView", "ButStsActive") == "true");

	var UpdLloAvail = (retrieveSi(srcdoc, "StatShrWzskLiv2DView", "UpdLloAvail") == "true");

	var UpdLuoAvail = (retrieveSi(srcdoc, "StatShrWzskLiv2DView", "UpdLuoAvail") == "true");

	var UpdLmdAvail = (retrieveSi(srcdoc, "StatShrWzskLiv2DView", "UpdLmdAvail") == "true");

	// IP refreshBD.vars --- END

	// IP refreshBD --- RBEGIN
	refreshButicon(hdrdoc, "ButClaim", "icon/claim", ButClaimActive, retrieveCi(srcdoc, "ContInfWzskLiv2DView", "ButClaimOn") == "true");
	contcontdoc.getElementById("PupPvm").value = retrieveCi(srcdoc, "ContIacWzskLiv2DView", "numFPupPvm");

	refreshButicon(contcontdoc, "ButPlay", "iconwzsk/play", ButPlayActive, false);
	refreshButicon(contcontdoc, "ButStop", "iconwzsk/stop", ButStopActive, false);

	refreshChk(contcontdoc, "ChkAex", (retrieveCi(srcdoc, "ContIacWzskLiv2DView", "ChkAex") == "true"), ChkAexActive);

	height -= setCtlAvail(contcontdoc, "Ext", SldExtAvail, 25);
	if (SldExtAvail) {
		refreshSld(contcontdoc, "SldExt", true, true, parseFloat(retrieveSi(srcdoc, "StatShrWzskLiv2DView", "SldExtMin")), parseFloat(retrieveSi(srcdoc, "StatShrWzskLiv2DView", "SldExtMax")), parseFloat(retrieveCi(srcdoc, "ContIacWzskLiv2DView", "SldExt")), SldExtActive, false);

	};

	refreshSld(contcontdoc, "SldFcs", true, false, parseFloat(retrieveSi(srcdoc, "StatShrWzskLiv2DView", "SldFcsMin")), parseFloat(retrieveSi(srcdoc, "StatShrWzskLiv2DView", "SldFcsMax")), parseFloat(retrieveCi(srcdoc, "ContIacWzskLiv2DView", "SldFcs")), SldFcsActive, false);

	height -= setCtlAvail(contcontdoc, "Oaf", TxtOafAvail, 25);
	if (TxtOafAvail) {
		refreshTxt(contcontdoc, "TxtOaf", retrieveCi(srcdoc, "ContInfWzskLiv2DView", "TxtOaf"));

	};

	refreshBut(contcontdoc, "ButSts", ButStsActive, false);

	refreshBut(contcontdoc, "ButTcc", true, retrieveCi(srcdoc, "ContInfWzskLiv2DView", "ButTccOn") == "true");
	refreshBut(contcontdoc, "ButTcw", true, retrieveCi(srcdoc, "ContInfWzskLiv2DView", "ButTcwOn") == "true");

	refreshBut(contcontdoc, "ButLle", true, retrieveCi(srcdoc, "ContInfWzskLiv2DView", "ButLleOn") == "true");
	refreshBut(contcontdoc, "ButLri", true, retrieveCi(srcdoc, "ContInfWzskLiv2DView", "ButLriOn") == "true");

	height -= setCtlAvail(contcontdoc, "Llo", UpdLloAvail, 25);
	if (UpdLloAvail) {
		refreshUpd(contcontdoc, "UpdLlo", parseInt(retrieveSi(srcdoc, "StatShrWzskLiv2DView", "UpdLloMin")), parseInt(retrieveSi(srcdoc, "StatShrWzskLiv2DView", "UpdLloMax")), parseInt(retrieveCi(srcdoc, "ContIacWzskLiv2DView", "UpdLlo")), true, false);

	};

	height -= setCtlAvail(contcontdoc, "Luo", UpdLuoAvail, 25);
	if (UpdLuoAvail) {
		refreshUpd(contcontdoc, "UpdLuo", parseInt(retrieveSi(srcdoc, "StatShrWzskLiv2DView", "UpdLuoMin")), parseInt(retrieveSi(srcdoc, "StatShrWzskLiv2DView", "UpdLuoMax")), parseInt(retrieveCi(srcdoc, "ContIacWzskLiv2DView", "UpdLuo")), true, false);

	};

	height -= setCtlAvail(contcontdoc, "Lmd", UpdLmdAvail, 25);
	if (UpdLmdAvail) {
		refreshUpd(contcontdoc, "UpdLmd", parseInt(retrieveSi(srcdoc, "StatShrWzskLiv2DView", "UpdLmdMin")), parseInt(retrieveSi(srcdoc, "StatShrWzskLiv2DView", "UpdLmdMax")), parseInt(retrieveCi(srcdoc, "ContIacWzskLiv2DView", "UpdLmd")), true, false);

	};

	refreshChk(contcontdoc, "ChkLgl", (retrieveCi(srcdoc, "ContIacWzskLiv2DView", "ChkLgl") == "true"), true);

	//
	var ChkLro = (retrieveCi(srcdoc, "ContIacWzskLiv2DView", "ChkLro") == "true");
	refreshChk(contcontdoc, "ChkLro", ChkLro, true);
	if (ChkLro) imgdoc.getElementById("roiTrace").setAttribute("display", "display");
	else imgdoc.getElementById("roiTrace").setAttribute("display", "none");

	refreshBut(contcontdoc, "ButLtr", true, retrieveCi(srcdoc, "ContInfWzskLiv2DView", "ButLtrOn") == "true");

	refreshUpd(contcontdoc, "UpdPnt", parseInt(retrieveSi(srcdoc, "StatShrWzskLiv2DView", "UpdPntMin")), parseInt(retrieveSi(srcdoc, "StatShrWzskLiv2DView", "UpdPntMax")), parseInt(retrieveCi(srcdoc, "ContIacWzskLiv2DView", "UpdPnt")), true, false);

	//
	var ChkPro = (retrieveCi(srcdoc, "ContIacWzskLiv2DView", "ChkPro") == "true");
	refreshChk(contcontdoc, "ChkPro", ChkPro, true);
	if (ChkPro) imgdoc.getElementById("roiCorner").setAttribute("display", "display");
	else imgdoc.getElementById("roiCorner").setAttribute("display", "none");

	refreshBut(contcontdoc, "ButPic", true, retrieveCi(srcdoc, "ContInfWzskLiv2DView", "ButPicOn") == "true");
	// IP refreshBD --- REND

	getCrdwnd().changeHeight("2DView", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("2DView_side").setAttribute("height", "" + (height+31));
	doc.getElementById("2DView_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("2DView_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLiv2DView", "srefIxWzskVExpstate");

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
	srcdoc = doc.getElementById("2DView_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzskInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

function handleCusImgLoad(cusdoc) {
	// IP handleCusImgLoad --- IBEGIN
	imgdoc = cusdoc;

	var cvs = imgdoc.getElementById("cvs");
	
	doc.scale = 1.0;
	doc.scale_svg = 1.0;

	doc.imgdat = cvs.getContext("2d").createImageData(cvs.width, cvs.height);
	// IP handleCusImgLoad --- IEND
};

function handleChkLglChange() {
	// IP handleChkLglChange --- IBEGIN
	if (contcontdoc.getElementById("ChkLgl").checked == true) imgdoc.getElementById("guide").setAttribute("stroke", "yellow");
	else imgdoc.getElementById("guide").setAttribute("stroke", "none");
	// IP handleChkLglChange --- IEND
};

function handleButLclClick() {
	// IP handleButLclClick --- IBEGIN
	clearElem(imgdoc.getElementById("traceL"));
	clearElem(imgdoc.getElementById("traceR"));
	// IP handleButLclClick --- IEND
};

function handleButPclClick() {
	// IP handleButPclClick --- IBEGIN
	clearElem(imgdoc.getElementById("corner"));
	// IP handleButPclClick --- IEND
};

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskLiv2DViewDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handleChkChange(_doc, ctlsref) {
	var elem = _doc.getElementById(ctlsref);
	var checked;

	elem.setAttribute("class", "chkmod");

	if (elem.checked == true) checked = "true"; else checked = "false";
	setCi(srcdoc, "ContIacWzskLiv2DView", ctlsref, checked);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskLiv2DViewData", scrJref, "ContIacWzskLiv2DView");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

function handlePupChange(_doc, ctlsref, size) {
	var elem = _doc.getElementById(ctlsref);

	elem.setAttribute("class", "pup" + size + "mod");
	setCi(srcdoc, "ContIacWzskLiv2DView", "numF" + ctlsref, elem.value);

	var str = serializeDpchAppData(srcdoc, "DpchAppWzskLiv2DViewData", scrJref, "ContIacWzskLiv2DView");
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

	if (shr) oldVal = parseFloat(retrieveCi(srcdoc, "ContIacWzskLiv2DView", ctlsref));
	else oldVal = parseFloat(_doc.getElementById(ctlsref + "Val").value);
	min = parseFloat(retrieveSi(srcdoc, "StatShrWzskLiv2DView", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrWzskLiv2DView", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrWzskLiv2DView", ctlsref + "Rast"));

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
		setCi(srcdoc, "ContIacWzskLiv2DView", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzskLiv2DViewData", scrJref, "ContIacWzskLiv2DView");
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

	if (shr) oldVal = parseFloat(retrieveCi(srcdoc, "ContIacWzskLiv2DView", ctlsref));
	else oldVal = parseFloat(_doc.getElementById(ctlsref + "Val").value);
	min = parseFloat(retrieveSi(srcdoc, "StatShrWzskLiv2DView", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrWzskLiv2DView", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrWzskLiv2DView", ctlsref + "Rast"));

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
		setCi(srcdoc, "ContIacWzskLiv2DView", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzskLiv2DViewData", scrJref, "ContIacWzskLiv2DView");
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

	min = parseFloat(retrieveSi(srcdoc, "StatShrWzskLiv2DView", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrWzskLiv2DView", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrWzskLiv2DView", ctlsref + "Rast"));
	else rast = 0.0;

	pos = getSldPosFromEvtx(true, evt.clientX);

	if (log) val = getSldLogvalFromPos(min, max, rast, pos);
	else val = getSldValFromPos(min, max, rast, pos);

	setSldPos(_doc, ctlsref, true, pos);
	setSldVal(_doc, ctlsref, val, true, true);

	if (shr) setCi(srcdoc, "ContIacWzskLiv2DView", ctlsref, "" + val);
	else window["handle" + ctlsref + "Change"](val);
};

function handleSldMup(_doc, ctlsref, shr) {
	_doc.getElementById("td" + ctlsref).onmousemove = null;
	_doc.getElementById("td" + ctlsref).onmouseup = null;

	if (shr) {
		var str = serializeDpchAppData(srcdoc, "DpchAppWzskLiv2DViewData", scrJref, "ContIacWzskLiv2DView");
		sendReq(str, doc, handleDpchAppDataDoReply);
	};
};

function handleSldValKey(_doc, ctlsref, shr, log, _rast, evt) {
	var elem = _doc.getElementById(ctlsref + "Val");

	var pos, val;

	var min, max, rast;

	elem.setAttribute("class", "txfxsmod");

	if (evt.keyCode == 13) {
		min = parseFloat(retrieveSi(srcdoc, "StatShrWzskLiv2DView", ctlsref + "Min"));
		max = parseFloat(retrieveSi(srcdoc, "StatShrWzskLiv2DView", ctlsref + "Max"));

		if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrWzskLiv2DView", ctlsref + "Rast"));
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
			setCi(srcdoc, "ContIacWzskLiv2DView", ctlsref, "" + val);

			var str = serializeDpchAppData(srcdoc, "DpchAppWzskLiv2DViewData", scrJref, "ContIacWzskLiv2DView");
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

	min = parseFloat(retrieveSi(srcdoc, "StatShrWzskLiv2DView", ctlsref + "Min"));
	max = parseFloat(retrieveSi(srcdoc, "StatShrWzskLiv2DView", ctlsref + "Max"));

	if (_rast) rast = parseFloat(retrieveSi(srcdoc, "StatShrWzskLiv2DView", ctlsref + "Rast"));
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
		setCi(srcdoc, "ContIacWzskLiv2DView", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzskLiv2DViewData", scrJref, "ContIacWzskLiv2DView");
		sendReq(str, doc, handleDpchAppDataDoReply);

	} else {
	window["handle" + ctlsref + "Change"](val);
	};
};

function handleUpdValKey(_doc, ctlsref, shr, evt) {
	var elem = _doc.getElementById(ctlsref + "Val");

	var val;

	var min, max;

	elem.setAttribute("class", "txfsmod");

	if (evt.keyCode == 13) {
		min = parseInt(retrieveSi(srcdoc, "StatShrWzskLiv2DView", ctlsref + "Min"));
		max = parseInt(retrieveSi(srcdoc, "StatShrWzskLiv2DView", ctlsref + "Max"));

		val = parseInt(elem.value);
		if (isNaN(val)) val = 0;
		if (val < min) val = min;
		if (val > max) val = max;

		refreshUpd(_doc, ctlsref, min, max, val, true, true);

		if (shr) {
			setCi(srcdoc, "ContIacWzskLiv2DView", ctlsref, "" + val);

			var str = serializeDpchAppData(srcdoc, "DpchAppWzskLiv2DViewData", scrJref, "ContIacWzskLiv2DView");
			sendReq(str, doc, handleDpchAppDataDoReply);

		} else {
			window["handle" + ctlsref + "Change"](val);
		};

		return false;
	};

	return true;
};

function handleUpdValChange(_doc, ctlsref, shr) {
	var elem = _doc.getElementById(ctlsref + "Val");

	var val;

	var min, max;

	elem.setAttribute("class", "txfsmod");

	min = parseInt(retrieveSi(srcdoc, "StatShrWzskLiv2DView", ctlsref + "Min"));
	max = parseInt(retrieveSi(srcdoc, "StatShrWzskLiv2DView", ctlsref + "Max"));

	val = parseInt(elem.value);
	if (isNaN(val)) val = 0;
	if (val < min) val = min;
	if (val > max) val = max;

	refreshUpd(_doc, ctlsref, min, max, val, true, true);

	if (shr) {
		setCi(srcdoc, "ContIacWzskLiv2DView", ctlsref, "" + val);

			var str = serializeDpchAppData(srcdoc, "DpchAppWzskLiv2DViewData", scrJref, "ContIacWzskLiv2DView");
		setCi(srcdoc, "ContIacWzskLiv2DView", ctlsref, "" + val);
		sendReq(str, doc, handleDpchAppDataDoReply);

	} else {
		window["handle" + ctlsref + "Change"](val);
	};
};

function handleUpdUpClick(_doc, ctlsref, shr) {
	var oldVal, val;

	var min, max;

	if (shr) oldVal = parseInt(retrieveCi(srcdoc, "ContIacWzskLiv2DView", ctlsref));
	else oldVal = parseInt(_doc.getElementById(ctlsref + "Val").value);
	min = parseInt(retrieveSi(srcdoc, "StatShrWzskLiv2DView", ctlsref + "Min"));
	max = parseInt(retrieveSi(srcdoc, "StatShrWzskLiv2DView", ctlsref + "Max"));

	val = oldVal + 1;
	if (val < min) val = min;
	if (val > max) val = max;

	refreshUpd(_doc, ctlsref, min, max, val, true, true);

	if (shr) {
		setCi(srcdoc, "ContIacWzskLiv2DView", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzskLiv2DViewData", scrJref, "ContIacWzskLiv2DView");
		sendReq(str, doc, handleDpchAppDataDoReply);

	} else {
		window["handle" + ctlsref + "Change"](val);
	};
};

function handleUpdDownClick(_doc, ctlsref, shr) {
	var oldVal, val;

	var min, max;

	if (shr) oldVal = parseInt(retrieveCi(srcdoc, "ContIacWzskLiv2DView", ctlsref));
	else oldVal = parseInt(_doc.getElementById(ctlsref + "Val").value);
	min = parseInt(retrieveSi(srcdoc, "StatShrWzskLiv2DView", ctlsref + "Min"));
	max = parseInt(retrieveSi(srcdoc, "StatShrWzskLiv2DView", ctlsref + "Max"));

	val = oldVal - 1;
	if (val < min) val = min;
	if (val > max) val = max;

	refreshUpd(_doc, ctlsref, min, max, val, true, true);

	if (shr) {
		setCi(srcdoc, "ContIacWzskLiv2DView", ctlsref, "" + val);

		var str = serializeDpchAppData(srcdoc, "DpchAppWzskLiv2DViewData", scrJref, "ContIacWzskLiv2DView");
		sendReq(str, doc, handleDpchAppDataDoReply);

	} else {
		window["handle" + ctlsref + "Change"](val);
	};
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWzskLiv2DViewData", "ContIacWzskLiv2DView", srcdoc)) mask.push("contiac");
	if (updateSrcblock(dom, "DpchEngWzskLiv2DViewData", "ContInfWzskLiv2DView", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWzskLiv2DViewData", "FeedFPupPvm", srcdoc)) mask.push("feedFPupPvm");
	if (updateSrcblock(dom, "DpchEngWzskLiv2DViewData", "StatShrWzskLiv2DView", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskLiv2DViewData", "TagWzskLiv2DView", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzskLiv2DViewData") {
		var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLiv2DView", "srefIxWzskVExpstate");

		var mask = mergeDpchEngData(dom);

		if (mask.indexOf("statshr") != -1) {
			var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLiv2DView", "srefIxWzskVExpstate");

			if (srefIxWzskVExpstate != oldSrefIxWzskVExpstate) {
				if (srefIxWzskVExpstate == "mind") minimize();
				else if (srefIxWzskVExpstate == "regd") regularize();
			} else {
				refresh();
			};

		} else {
			refresh();
		};
	} else if (dpch == "DpchEngWzskLiv2DViewLive") {
		handleDpchEngWzskLiv2DViewLive(dom);
	} else if (dpch == "DpchEngWzskLiv2DViewAlign") {
		handleDpchEngWzskLiv2DViewAlign(dom);
	};
};

function handleDpchEngWzskLiv2DViewLive(dom) {
	// IP handleDpchEngWzskLiv2DViewLive --- IBEGIN
	var mask = [];

	var resnode;

	// gray
	resnode = getNode(dom, "//wzsk:DpchEngWzskLiv2DViewLive/wzsk:gray");
	if (resnode) {
		doc.gray = parseUtinyintvec(resnode.textContent);
		mask.push("gray");
	};

	// RGB
	resnode = getNode(dom, "//wzsk:DpchEngWzskLiv2DViewLive/wzsk:red");
	if (resnode) {
		doc.red = parseUtinyintvec(resnode.textContent);
		mask.push("red");
	};

	resnode = getNode(dom, "//wzsk:DpchEngWzskLiv2DViewLive/wzsk:green");
	if (resnode) {
		doc.green = parseUtinyintvec(resnode.textContent);
		mask.push("green");
	};

	resnode = getNode(dom, "//wzsk:DpchEngWzskLiv2DViewLive/wzsk:blue");
	if (resnode) {
		doc.blue = parseUtinyintvec(resnode.textContent);
		mask.push("blue");
	};

	// corner
	resnode = getNode(dom, "//wzsk:DpchEngWzskLiv2DViewLive/wzsk:xCorner");
	if (resnode) {
		doc.xCorner = parseIntvec(resnode.textContent);
		mask.push("xCorner");
	};

	resnode = getNode(dom, "//wzsk:DpchEngWzskLiv2DViewLive/wzsk:yCorner");
	if (resnode) {
		doc.yCorner = parseIntvec(resnode.textContent);
		mask.push("yCorner");
	};

	// trace left
	resnode = getNode(dom, "//wzsk:DpchEngWzskLiv2DViewLive/wzsk:xTraceL");
	if (resnode) {
		doc.xTraceL = parseIntvec(resnode.textContent);
		mask.push("xTraceL");
	};

	resnode = getNode(dom, "//wzsk:DpchEngWzskLiv2DViewLive/wzsk:yTraceL");
	if (resnode) {
		doc.yTraceL = parseIntvec(resnode.textContent);
		mask.push("yTraceL");
	};

	// trace right
	resnode = getNode(dom, "//wzsk:DpchEngWzskLiv2DViewLive/wzsk:xTraceR");
	if (resnode) {
		doc.xTraceR = parseIntvec(resnode.textContent);
		mask.push("xTraceR");
	};

	resnode = getNode(dom, "//wzsk:DpchEngWzskLiv2DViewLive/wzsk:yTraceR");
	if (resnode) {
		doc.yTraceR = parseIntvec(resnode.textContent);
		mask.push("yTraceR");
	};

	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLiv2DView", "srefIxWzskVExpstate");
	if (srefIxWzskVExpstate == "regd") refreshLive(mask);
	// IP handleDpchEngWzskLiv2DViewLive --- IEND
};

function handleDpchEngWzskLiv2DViewAlign(dom) {
	// IP handleDpchEngWzskLiv2DViewAlign --- IBEGIN
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWzskLiv2DViewAlign", "ContIacWzskLiv2DViewCorner", srcdoc)) mask.push("contiaccorner");
	if (updateSrcblock(dom, "DpchEngWzskLiv2DViewAlign", "ContIacWzskLiv2DViewTrace", srcdoc)) mask.push("contiactrace");

	//var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLiv2DView", "srefIxWzskVExpstate");
	//if (srefIxWzskVExpstate == "regd") {
		if (mask.indexOf("contiaccorner") != -1) refreshRoi(false);
		if (mask.indexOf("contiactrace") != -1) refreshRoi(true);
	//};
	// IP handleDpchEngWzskLiv2DViewAlign --- IEND
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wzsk:*");
		if (blk) {
			if (blk.nodeName == "DpchEngWzskLiv2DViewData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("2DView");
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

			} else if (blk.nodeName == "DpchEngWzskLiv2DViewData") {
				var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLiv2DView", "srefIxWzskVExpstate");

				var mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLiv2DView", "srefIxWzskVExpstate");

					if (srefIxWzskVExpstate != oldSrefIxWzskVExpstate) {
						if (srefIxWzskVExpstate == "mind") minimize();
						else if (srefIxWzskVExpstate == "regd") regularize();
					} else {
						refresh();
					};

				} else {
					refresh();
				};

			} else if (blk.nodeName == "DpchEngWzskLiv2DViewAlign") {
				handleDpchEngWzskLiv2DViewAlign(dom);
			};
		};
	};
};



