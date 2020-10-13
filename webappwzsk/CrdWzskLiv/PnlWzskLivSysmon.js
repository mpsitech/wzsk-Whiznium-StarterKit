/**
  * \file PnlWzskLivSysmon.js
  * web client functionality for panel PnlWzskLivSysmon
  * \author Catherine Johnson
  * \date created: 13 Oct 2020
  * \date modified: 13 Oct 2020
  */

// IP cust --- IBEGIN
function refreshCusPlt(cusdoc) {
	if (!getNode(srcdoc, "//wzsk:ts")) return;
	if (!getNode(srcdoc, "//wzsk:cldtots")) return;

	var mytext;

	var yss = ["cldtots"];
	if (getNode(srcdoc, "//wzsk:cld1s")) yss.push("cld1s");
	if (getNode(srcdoc, "//wzsk:cld2s")) yss.push("cld2s");
	if (getNode(srcdoc, "//wzsk:cld3s")) yss.push("cld3s");
	if (getNode(srcdoc, "//wzsk:cld4s")) yss.push("cld4s");

	var firstys = [];

	plotXY(cusdoc, srcdoc, 690, 250, "ts", "f", false, -60.0, 0.0, retrieveTi(srcdoc, "TagWzskLivSysmon", "CptPltTme"), yss, "f", 0.0, 100.0, retrieveTi(srcdoc, "TagWzskLivSysmon", "CptPltCld"), firstys);

	// update latest
	mytext = cusdoc.getElementById("latestCldtot");
	clearElem(mytext);
	if (firstys.length > 0) mytext.appendChild(cusdoc.createTextNode(retrieveTi(srcdoc, "TagWzskLivSysmon", "CptPltTot") + ": " + Math.round(firstys[0]) + "%"));

	mytext = cusdoc.getElementById("latestCld1");
	clearElem(mytext);
	if (firstys.length > 1) mytext.appendChild(cusdoc.createTextNode(retrieveTi(srcdoc, "TagWzskLivSysmon", "CptPltCor") + " 1: " + Math.round(firstys[1]) + "%"));

	mytext = cusdoc.getElementById("latestCld2");
	clearElem(mytext);
	if (firstys.length > 2) mytext.appendChild(cusdoc.createTextNode(retrieveTi(srcdoc, "TagWzskLivSysmon", "CptPltCor") + " 2: " + Math.round(firstys[2]) + "%"));

	mytext = cusdoc.getElementById("latestCld3");
	clearElem(mytext);
	if (firstys.length > 3) mytext.appendChild(cusdoc.createTextNode(retrieveTi(srcdoc, "TagWzskLivSysmon", "CptPltCor") + " 3: " + Math.round(firstys[3]) + "%"));

	mytext = cusdoc.getElementById("latestCld4");
	clearElem(mytext);
	if (firstys.length > 4) mytext.appendChild(cusdoc.createTextNode(retrieveTi(srcdoc, "TagWzskLivSysmon", "CptPltCor") + " 4: " + Math.round(firstys[4]) + "%"));
};
// IP cust --- IEND

// --- expand state management
function minimize() {
	// change container heights
	getCrdwnd().changeHeight("Sysmon", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Sysmon_side").setAttribute("height", "30");
	doc.getElementById("Sysmon_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Sysmon_side").src = "./PnlWzskLivSysmon_aside.html";
	doc.getElementById("Sysmon_cont").src = "./PnlWzskLivSysmon_a.html";
};

function regularize() {
	// change content (container heights in refreshBD)
	doc.getElementById("Sysmon_side").src = "./PnlWzskLivSysmon_bside.html";
	doc.getElementById("Sysmon_cont").src = "./PnlWzskLivSysmon_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Sysmon_side").contentDocument;
	contdoc = doc.getElementById("Sysmon_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzskLivSysmon", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Sysmon_side").contentDocument;
	contdoc = doc.getElementById("Sysmon_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Sysmon_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Sysmon_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWzskLivSysmon", "Cpt"));
	initCpt(contcontdoc, "CptCtp", retrieveTi(srcdoc, "TagWzskLivSysmon", "CptCtp"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLivSysmon", "srefIxWzskVExpstate");

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

	var height = 292; // full cont height

	// IP refreshBD.vars --- BEGIN

	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	refreshTxt(contcontdoc, "TxtCtp", retrieveCi(srcdoc, "ContInfWzskLivSysmon", "TxtCtp"));

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Sysmon", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Sysmon_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Sysmon_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Sysmon_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLivSysmon", "srefIxWzskVExpstate");

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
	srcdoc = doc.getElementById("Sysmon_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzskInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

function handleCusPltLoad(cusdoc) {
	// IP handleCusPltLoad --- INSERT
};

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskLivSysmonDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWzskLivSysmonData", "ContInfWzskLivSysmon", srcdoc)) mask.push("continf");
	if (updateSrcblock(dom, "DpchEngWzskLivSysmonData", "StatShrWzskLivSysmon", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskLivSysmonData", "TagWzskLivSysmon", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzskLivSysmonData") {
		var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLivSysmon", "srefIxWzskVExpstate");

		var mask = mergeDpchEngData(dom);

		if (mask.indexOf("statshr") != -1) {
			var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLivSysmon", "srefIxWzskVExpstate");

			if (srefIxWzskVExpstate != oldSrefIxWzskVExpstate) {
				if (srefIxWzskVExpstate == "mind") minimize();
				else if (srefIxWzskVExpstate == "regd") regularize();
			} else {
				refresh();
			};

		} else {
			refresh();
		};
	} else if (dpch == "DpchEngWzskLivSysmonLive") {
		handleDpchEngWzskLivSysmonLive(dom);
	};
};

function handleDpchEngWzskLivSysmonLive(dom) {
	// IP handleDpchEngWzskLivSysmonLive --- IBEGIN
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWzskLivSysmonLive", "ts", srcdoc)) mask.push("ts");
	if (updateSrcblock(dom, "DpchEngWzskLivSysmonLive", "cldtots", srcdoc)) mask.push("cldtots");
	if (updateSrcblock(dom, "DpchEngWzskLivSysmonLive", "cld1s", srcdoc)) mask.push("cld1s");
	if (updateSrcblock(dom, "DpchEngWzskLivSysmonLive", "cld2s", srcdoc)) mask.push("cld2s");
	if (updateSrcblock(dom, "DpchEngWzskLivSysmonLive", "cld3s", srcdoc)) mask.push("cld3s");
	if (updateSrcblock(dom, "DpchEngWzskLivSysmonLive", "cld4s", srcdoc)) mask.push("cld4s");

	if (!mask.empty && contcontdoc) {
		refreshCusPlt(contcontdoc.getElementById("CusPlt").contentDocument);
	};
	// IP handleDpchEngWzskLivSysmonLive --- IEND
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wzsk:*");
		if (blk) {
			if (blk.nodeName == "DpchEngWzskLivSysmonData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Sysmon");
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

			} else if (blk.nodeName == "DpchEngWzskLivSysmonData") {
				var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLivSysmon", "srefIxWzskVExpstate");

				var mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskLivSysmon", "srefIxWzskVExpstate");

					if (srefIxWzskVExpstate != oldSrefIxWzskVExpstate) {
						if (srefIxWzskVExpstate == "mind") minimize();
						else if (srefIxWzskVExpstate == "regd") regularize();
					} else {
						refresh();
					};

				} else {
					refresh();
				};
			} else if (blk.nodeName == "DpchEngWzskLivSysmonLive") {
				handleDpchEngWzskLivSysmonLive(dom);
			};
		};
	};
};



