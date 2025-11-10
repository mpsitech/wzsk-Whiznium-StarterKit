// IP cust --- IBEGIN
function refreshCusApl(cusdoc) {
	if (!getNode(srcdoc, "//wzsk:ts")) return;
	if (!getNode(srcdoc, "//wzsk:phis")) return;

	var yss = [];
	yss.push("phis");

	plotXY(cusdoc, srcdoc, 690, 250, "ts", "f", false, 0.0, 0.0, retrieveTi(srcdoc, "TagWzskVtrMonitor", "CptAplTme"), yss, "f", 0.0, 0.0, retrieveTi(srcdoc, "TagWzskVtrMonitor", "CptAplAng"), null);
};

function refreshCusVpl(cusdoc) {
	if (!getNode(srcdoc, "//wzsk:ts")) return;
	if (!getNode(srcdoc, "//wzsk:omegas")) return;

	var yss = [];
	yss.push("omegas");

	plotXY(cusdoc, srcdoc, 690, 250, "ts", "f", false, 0.0, 0.0, retrieveTi(srcdoc, "TagWzskVtrMonitor", "CptVplTme"), yss, "f", 0.0, 0.0, retrieveTi(srcdoc, "TagWzskVtrMonitor", "CptVplAng"), null);
};
// IP cust --- IEND

// --- expand state management
function minimize() {
	// change container heights
	getCrdwnd().changeHeight("Monitor", 30);
	doc.getElementById("tdSide").setAttribute("height", "30");
	doc.getElementById("Monitor_side").setAttribute("height", "30");
	doc.getElementById("Monitor_cont").setAttribute("height", "30");

	// change content
	doc.getElementById("Monitor_side").src = "./PnlWzskVtrMonitor_aside.html";
	doc.getElementById("Monitor_cont").src = "./PnlWzskVtrMonitor_a.html";
};

function regularize() {
	// change content (container heights in refreshBD)
	doc.getElementById("Monitor_side").src = "./PnlWzskVtrMonitor_bside.html";
	doc.getElementById("Monitor_cont").src = "./PnlWzskVtrMonitor_b.html";
};

// --- view initialization and refresh
function initA() {
	if (!doc) return;

	sidedoc = doc.getElementById("Monitor_side").contentDocument;
	contdoc = doc.getElementById("Monitor_cont").contentDocument;
	hdrdoc = null;
	contcontdoc = null;
	ftrdoc = null;

	initCpt(contdoc, "Cpt", retrieveTi(srcdoc, "TagWzskVtrMonitor", "Cpt"));

	refreshA();
};

function initBD(bNotD) {
	if (!doc) return;

	sidedoc = doc.getElementById("Monitor_side").contentDocument;
	contdoc = doc.getElementById("Monitor_cont").contentDocument;
	hdrdoc = contdoc.getElementById("Monitor_hdr").contentDocument;
	contcontdoc = contdoc.getElementById("Monitor_cont").contentDocument;

	// IP initBD --- BEGIN
	initCpt(hdrdoc, "Cpt", retrieveTi(srcdoc, "TagWzskVtrMonitor", "Cpt"));
	// IP initBD --- END

	refreshBD(bNotD);
};

function init() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskVtrMonitor", "srefIxWzskVExpstate");

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

	var height = 510; // full cont height

	// IP refreshBD.vars --- BEGIN
	var CusAplHeight = parseInt(retrieveSi(srcdoc, "StatShrWzskVtrMonitor", "CusAplHeight"));

	var CusVplHeight = parseInt(retrieveSi(srcdoc, "StatShrWzskVtrMonitor", "CusVplHeight"));

	// IP refreshBD.vars --- END

	// IP refreshBD --- BEGIN
	mytd = contcontdoc.getElementById("tdApl");
	mytd.setAttribute("height", "" + CusAplHeight);
	contcontdoc.getElementById("CusApl").setAttribute("height", "" + CusAplHeight);
	height += CusAplHeight-250;

	mytd = contcontdoc.getElementById("tdVpl");
	mytd.setAttribute("height", "" + CusVplHeight);
	contcontdoc.getElementById("CusVpl").setAttribute("height", "" + CusVplHeight);
	height += CusVplHeight-250;

	// IP refreshBD --- END

	getCrdwnd().changeHeight("Monitor", height+31);
	doc.getElementById("tdSide").setAttribute("height", "" + (height+31));
	doc.getElementById("Monitor_side").setAttribute("height", "" + (height+31));
	doc.getElementById("Monitor_cont").setAttribute("height", "" + (height+31));
	sidedoc.getElementById("tdFlex").setAttribute("height", "" + (height+31-30));
	contdoc.getElementById("tdCont").setAttribute("height", "" + height);
	contdoc.getElementById("Monitor_cont").setAttribute("height", "" + height);
};

function refresh() {
	var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskVtrMonitor", "srefIxWzskVExpstate");

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
	srcdoc = doc.getElementById("Monitor_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzskInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

// --- specific event handlers for app controls

function handleCusAplLoad(cusdoc) {
	// IP handleCusAplLoad --- INSERT
};

function handleCusVplLoad(cusdoc) {
	// IP handleCusVplLoad --- INSERT
};

// --- generalized event handlers for app controls

// --- generalized event handlers for shared controls

function handleButClick(ctlsref) {
	var str = serializeDpchAppDo(srcdoc, "DpchAppWzskVtrMonitorDo", scrJref, ctlsref + "Click");
	sendReq(str, doc, handleDpchAppDataDoReply);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	// IP mergeDpchEngData --- BEGIN
	if (updateSrcblock(dom, "DpchEngWzskVtrMonitorData", "StatShrWzskVtrMonitor", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskVtrMonitorData", "TagWzskVtrMonitor", srcdoc)) mask.push("tag");
	// IP mergeDpchEngData --- END

	return mask;
};

function handleDpchEng(dom, dpch) {
	if (dpch == "DpchEngWzskVtrMonitorData") {
		var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskVtrMonitor", "srefIxWzskVExpstate");

		var mask = mergeDpchEngData(dom);

		if (mask.indexOf("statshr") != -1) {
			var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskVtrMonitor", "srefIxWzskVExpstate");

			if (srefIxWzskVExpstate != oldSrefIxWzskVExpstate) {
				if (srefIxWzskVExpstate == "mind") minimize();
				else if (srefIxWzskVExpstate == "regd") regularize();
			} else {
				refresh();
			};

		} else {
			refresh();
		};
	} else if (dpch == "DpchEngWzskVtrMonitorLive") {
		handleDpchEngWzskVtrMonitorLive(dom);
	};
};

function handleDpchEngWzskVtrMonitorLive(dom) {
	// IP handleDpchEngWzskVtrMonitorLive --- IBEGIN
console.log("beep");
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWzskVtrMonitorLive", "ts", srcdoc)) mask.push("ts");
	if (updateSrcblock(dom, "DpchEngWzskVtrMonitorLive", "phis", srcdoc)) mask.push("phis");
	if (updateSrcblock(dom, "DpchEngWzskVtrMonitorLive", "phiMin", srcdoc)) mask.push("phiMin");
	if (updateSrcblock(dom, "DpchEngWzskVtrMonitorLive", "phiMax", srcdoc)) mask.push("phiMax");
	if (updateSrcblock(dom, "DpchEngWzskVtrMonitorLive", "omegas", srcdoc)) mask.push("omegas");
	if (updateSrcblock(dom, "DpchEngWzskVtrMonitorLive", "omegaMin", srcdoc)) mask.push("omegaMin");
	if (updateSrcblock(dom, "DpchEngWzskVtrMonitorLive", "omegaMax", srcdoc)) mask.push("omegaMax");
console.log(mask);

	if (!mask.empty && contcontdoc) {
		refreshCusApl(contcontdoc.getElementById("CusApl").contentDocument);
		refreshCusVpl(contcontdoc.getElementById("CusVpl").contentDocument);
	};
	// IP handleDpchEngWzskVtrMonitorLive --- IEND
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wzsk:*");
		if (blk) {
			if (blk.nodeName == "DpchEngWzskVtrMonitorData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Monitor");
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

			} else if (blk.nodeName == "DpchEngWzskVtrMonitorData") {
				var oldSrefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskVtrMonitor", "srefIxWzskVExpstate");

				var mask = mergeDpchEngData(dom);

				if (mask.indexOf("statshr") != -1) {
					var srefIxWzskVExpstate = retrieveSi(srcdoc, "StatShrWzskVtrMonitor", "srefIxWzskVExpstate");

					if (srefIxWzskVExpstate != oldSrefIxWzskVExpstate) {
						if (srefIxWzskVExpstate == "mind") minimize();
						else if (srefIxWzskVExpstate == "regd") regularize();
					} else {
						refresh();
					};

				} else {
					refresh();
				};
			} else if (blk.nodeName == "DpchEngWzskVtrMonitorLive") {
				handleDpchEngWzskVtrMonitorLive(dom);
			};
		};
	};
};
