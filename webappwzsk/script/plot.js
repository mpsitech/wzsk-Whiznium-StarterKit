// IP file --- KEEP

function rgbmap(
			val
		) {
	// blue -> green -> yellow -> orange -> red
	var rgb = new Uint8Array(3);

	if (val == 0.0) {
		rgb[0] = 127;
		rgb[1] = 127;
		rgb[2] = 127;
	} else if (val < 0.25) {
		rgb[0] = 0;
		rgb[1] = Math.round(255.0 * 4.0*(val));
		rgb[2] = 255;
	} else if ((val >= 0.25) && (val < 0.5)) {
		rgb[0] = 0;
		rgb[1] = 255;
		rgb[2] = Math.round(255.0 * 4.0*(0.5-val));
	} else if ((val >= 0.5) && (val < 0.75)) {
		rgb[0] = Math.round(255.0 * 4.0*(val-0.5));
		rgb[1] = 255;
		rgb[2] = 0;
	} else {
		rgb[0] = 255;
		rgb[1] = Math.round(255.0 * 4.0*(1.0-val));
		rgb[2] = 0;
	};

	return rgb;
};

function plot2DCvs(
			contdoc, imgdat
			, width, height
			, xs, xmin, xmax, xlabel
			, ys, ymin, ymax, ylabel
			, As, Amin, Amax
		) {
	// expect cvs which is a canvas, and axes within an svg

	// expect xs, ys, As already parsed (e.g. Intvec/Floatvec/Doublevec)

	// xmin == xmax: derive from xs
	// ymin == ymax: derive from ys
	// Amin, Amax mandatory

	var axes
	
	var cvs, cvsctx;
	var d;

	var xpr, ypr;

	var mypath, myline, mytext;

	// -- scaling
	if (xmin == xmax) {
		// derive limits from xs
		xmin = 1.0e36;
		xmax = -1.0e36

		for (var i = 0; i < xs.length; i++) {
			if (xs[i] < xmin) xmin = xs[i];
			if (xs[i] > xmax) xmax = xs[i];
		};
	};

	if (xmin == xmax) {
		xmin = 0;
		xmax = 1;
	};

	if (ymin == ymax) {
		// derive limits from ys
		ymin = 1.0e36;
		ymax = -1.0e36

		for (var i = 0; i < ys.length; i++) {
			if (ys[i] < ymin) ymin = ys[i];
			if (ys[i] > ymax) ymax = ys[i];
		};
	};

	if (ymin == ymax) {
		ymin = 0;
		ymax = 1;
	};

	var left = 60;
	var top = 50;
	var right = 60;
	var bottom = 45;

	var xscale = ((width-right)-left)/(xmax-xmin);
	var yscale = ((height-bottom)-top)/(ymax-ymin);

	var xNtick = 5;
	var yNtick = 3;

	var dtick;
	var on;

	// -- x-axis
	axes = contdoc.getElementById("axes");

	clearElem(axes);

	// - line and arrow
	if ((xmin <= 0.0) && (xmax >= 0.0)) {
		xpr = 0.0;

		xpr = Math.floor(left + (xpr-xmin)*xscale) + 0.5;

		myline = contdoc.createElementNS("http://www.w3.org/2000/svg", "svg:line");
		myline.setAttribute("class", "zero");
		myline.setAttribute("x1", "" + xpr);
		myline.setAttribute("y1", "" + (height-(bottom-7.5)));
		myline.setAttribute("x2", "" + xpr);
		myline.setAttribute("y2", "" + (top-15));
		axes.appendChild(myline);
	};

	mypath = contdoc.createElementNS("http://www.w3.org/2000/svg", "svg:path");
	mypath.setAttribute("class", "axis");
	mypath.setAttribute("stroke", "black");
	mypath.setAttribute("d", "M " + left + "," + (height-(bottom-7.5)) + " L " + (width-right+20) + "," + (height-(bottom-7.5)));
	axes.appendChild(mypath);

	mypath = contdoc.createElementNS("http://www.w3.org/2000/svg", "svg:path");
	mypath.setAttribute("d", "M " + (width-right+30) + "," + (height-(bottom-7.5)) + " L " + (width-right+15) + "," + (height-(bottom-4.5)) + " L " + (width-right+15) + "," + (height-(bottom-10.5)));
	axes.appendChild(mypath);

	// - label
	mytext = contdoc.createElementNS("http://www.w3.org/2000/svg", "svg:text");
	mytext.setAttribute("class", "unit");
	mytext.setAttribute("text-anchor", "middle");
	mytext.setAttribute("x", "" + (left+(width-left-right)/2));
	mytext.setAttribute("y", "" + (height-(bottom-40)));
	mytext.appendChild(contdoc.createTextNode(xlabel));
	axes.appendChild(mytext);

	// - ticks, annot
	dtick = (xmax-xmin)/(xNtick-1);
	on = true;

	ypr = (height-(bottom-7.5));

	for (var i = 0; i < xNtick; i++) {
		xpr = xmin + i*dtick;
		xpr = Math.floor(left + (xpr-xmin)*xscale) + 0.5;

		myline = contdoc.createElementNS("http://www.w3.org/2000/svg", "svg:line");
		myline.setAttribute("class", "tick");
		myline.setAttribute("x1", "" + xpr);
		myline.setAttribute("y1", "" + (ypr-5));
		myline.setAttribute("x2", "" + xpr);
		myline.setAttribute("y2", "" + (ypr+5));
		axes.appendChild(myline);

		if (on) {
			mytext = contdoc.createElementNS("http://www.w3.org/2000/svg", "svg:text");
			mytext.setAttribute("class", "annot");
			mytext.setAttribute("text-anchor", "middle");
			mytext.setAttribute("x", "" + xpr);
			mytext.setAttribute("y", "" + (ypr+16));
			mytext.appendChild(contdoc.createTextNode("" + (xmin + i*dtick).toPrecision(4)));
			axes.appendChild(mytext);
		};

		on = !on;
	};

	// -- y-axis

	// - line and arrow
	ypr = ymin;
	ypr = Math.floor(height - bottom) + 0.5;

	myline = contdoc.createElementNS("http://www.w3.org/2000/svg", "svg:line");
	myline.setAttribute("class", "zero");
	myline.setAttribute("x1", "" + (left-7.5));
	myline.setAttribute("y1", "" + ypr);
	myline.setAttribute("x2", "" + (width-right+15));
	myline.setAttribute("y2", "" + ypr);
	axes.appendChild(myline);

	ypr = ymax;
	ypr = Math.floor(height - ((ypr-ymin)*yscale+bottom)) + 0.5;

	myline = contdoc.createElementNS("http://www.w3.org/2000/svg", "svg:line");
	myline.setAttribute("class", "zero");
	myline.setAttribute("x1", "" + (left-7.5));
	myline.setAttribute("y1", "" + ypr);
	myline.setAttribute("x2", "" + (width-right+15));
	myline.setAttribute("y2", "" + ypr);
	axes.appendChild(myline);

	if ((ymin < 0.0) && (ymax > 0.0)) {
		ypr = 0.0;
		ypr = Math.floor(height - ((ypr-ymin)*yscale+bottom)) + 0.5;

		myline = contdoc.createElementNS("http://www.w3.org/2000/svg", "svg:line");
		myline.setAttribute("class", "zero");
		myline.setAttribute("x1", "" + (left-7.5));
		myline.setAttribute("y1", "" + ypr);
		myline.setAttribute("x2", "" + (width-right+15));
		myline.setAttribute("y2", "" + ypr);
		axes.appendChild(myline);

	};

	mypath = contdoc.createElementNS("http://www.w3.org/2000/svg", "svg:path");
	mypath.setAttribute("class", "axis");
	mypath.setAttribute("stroke", "black");
	mypath.setAttribute("d", "M " + (left-7.5) + "," + (height-bottom) + " L " + (left-7.5) + "," + (top-20));
	axes.appendChild(mypath);

	mypath = contdoc.createElementNS("http://www.w3.org/2000/svg", "svg:path");
	mypath.setAttribute("d", "M " + (left-7.5) + "," + (top-30) + " L " + (left-10.5) + "," + (top-15) + " L " + (left-4.5) + "," + (top-15));
	axes.appendChild(mypath);

	// - label
	mytext = contdoc.createElementNS("http://www.w3.org/2000/svg", "svg:text");
	mytext.setAttribute("class", "unit");
	mytext.setAttribute("text-anchor", "middle");
	mytext.setAttribute("x", "0");
	mytext.setAttribute("y", "0");
	mytext.setAttribute("transform", "translate(" + (left-40) + "," + (top+(height-top-bottom)/2) + ") rotate(-90)");
	mytext.appendChild(contdoc.createTextNode(ylabel));
	axes.appendChild(mytext);

	// - ticks, annot
	dtick = (ymax-ymin)/(yNtick-1);
	on = true;

	xpr = left-7.5;

	for (var i = 0; i < yNtick; i++) {
		ypr = ymin + i*dtick;
		ypr = Math.floor(height - ((ypr-ymin)*yscale+bottom)) + 0.5;

		myline = contdoc.createElementNS("http://www.w3.org/2000/svg", "svg:line");
		myline.setAttribute("class", "tick");
		myline.setAttribute("x1", "" + (xpr-5));
		myline.setAttribute("y1", "" + ypr);
		myline.setAttribute("x2", "" + (xpr+5));
		myline.setAttribute("y2", "" + ypr);
		axes.appendChild(myline);

		if (on) {
			mytext = contdoc.createElementNS("http://www.w3.org/2000/svg", "svg:text");
			mytext.setAttribute("class", "annot");
			mytext.setAttribute("text-anchor", "end");
			mytext.setAttribute("x", "" + (xpr-8));
			mytext.setAttribute("y", "" + (ypr+4));
			mytext.appendChild(contdoc.createTextNode("" + (ymin + i*dtick).toPrecision(4)));
			axes.appendChild(mytext);
		};

		on = !on;
	};

	// -- amplitudes
	cvs = contdoc.getElementById("cvs");
	cvsctx = cvs.getContext("2d");
	
	// init to gray
	d = imgdat.data;

	for (var i = top; i < (height-bottom); i++)
		for (var j = left; j < (width-right); j++) {
			var ix2 = 4 * (i*width + j);

			d[ix2] = 127;
			d[ix2 + 1] = 127;
			d[ix2 + 2] = 127;
			d[ix2 + 3] = 255;
		};

	cvsctx.putImageData(imgdat, 0, 0);

	// actual data
	for (var i = 0; i < xs.length; i++) {
		var x0, w;
		var x0p, wp;

		if (i == 0) x0 = xs[0];
		else x0 = 0.5 * (xs[i-1] + xs[i]);

		if ((i + 1) == xs.length) w = xs[i] - x0;//x1 = xs[i];
		else w = 0.5 * (xs[i] + xs[i+1]) - x0;//x1 = 0.5 * (xs[i] + xs[i+1]);

		x0p = left + (x0-xmin)*xscale;
		wp = w*xscale;
		
		for (var j = 0; j < ys.length; j++) {
			var y0, h;
			var y0p, hp;

			if (j == 0) y0 = ys[0];
			else y0 = 0.5 * (ys[j-1] + ys[j]);
	
			if ((j + 1) == ys.length) h = ys[j] - y0;//y1 = ys[j];
			else h = 0.5 * (ys[j] + ys[j+1]) - y0;//y1 = 0.5 * (ys[j] + ys[j+1]);
	
			y0p = height - ((y0-ymin)*yscale+bottom);
			hp = h*yscale;

			var rgb = rgbmap((As[j*xs.length + i] - Amin) / (Amax - Amin));
			cvsctx.fillStyle = "rgb(" + rgb[0] + "," + rgb[1] + "," + rgb[2] + ")";

			cvsctx.fillRect(x0p, y0p - hp, wp, hp);
		};
	};
};

function plotXY(
			contdoc, srcdoc
			, width, height
			, xs, xtype, xDiffNotAbs, xmin, xmax, xlabel
			, yss, ytype, ymin, ymax, ylabel
			, firstys
		) {
	// TBD: re-evaluate srcdoc dependency

	// {x/y}type: "i"/"f"/"d" (int/float/double)

	// xmin == xmax: derive from xs
	// ymin == ymax: derive from yss

	// yss can refer to multiple vector nodes

	var xs, ys;

	var axes, xydata;

	var xpr, ypr;

	var mypath, myline, mytext;
	var stroke;

	var d;
	var first;

	if (xtype == "i") xs = parseIntvec(getNode(srcdoc, "//frdp:" + xs).textContent);
	else if (xtype == "f") xs = parseFloatvec(getNode(srcdoc, "//frdp:" + xs).textContent);
	else if (xtype == "d") xs = parseDoublevec(getNode(srcdoc, "//frdp:" + xs).textContent);

	if (firstys) while (firstys.length > 0) firstys.pop();

	// -- scaling
	if (xmin == xmax) {
		// derive limits from xs
		xmin = 1.0e36;
		xmax = -1.0e36

		for (var i = 0; i < xs.length; i++) {
			if (xs[i] < xmin) xmin = xs[i];
			if (xs[i] > xmax) xmax = xs[i];
		};
	};

	if (xmin == xmax) {
		xmin = 0;
		xmax = 1;

	} else if (xDiffNotAbs) {
		// values in xs are interpreted as backwards from last value (?)
		xmin -= xmax;
		xmax = 0.0;
	};

	if (ymin == ymax) {
		// derive limits from yss
		ymin = 1.0e36;
		ymax = -1.0e36

		for (var i = 0; i < yss.length; i++) {
			if (yss[i] == "") continue;
			if (!getNode(srcdoc, "//frdp:" + yss[i])) continue;

			ys = null;

			if (ytype == "i") ys = parseIntvec(getNode(srcdoc, "//frdp:" + yss[i]).textContent);
			else if (ytype == "f") ys = parseFloatvec(getNode(srcdoc, "//frdp:" + yss[i]).textContent);
			else if (ytype == "d") ys = parseDoublevec(getNode(srcdoc, "//frdp:" + yss[i]).textContent);

			if (!ys) continue;

			for (var j = 0; j < ys.length; j++) {
				if (ys[j] < ymin) ymin = ys[j];
				if (ys[j] > ymax) ymax = ys[j];
			};
		};
	};

	var left = 60;
	var top = 50;
	var right = 60;
	var bottom = 45;

	var xscale = ((width-right)-left)/(xmax-xmin);
	var yscale = ((height-bottom)-top)/(ymax-ymin);

	var xNtick = 5;
	var yNtick = 3;

	var dtick;
	var on;

	// -- x-axis
	axes = contdoc.getElementById("axes");

	clearElem(axes);

	// - line and arrow
	if ((xmin <= 0.0) && (xmax >= 0.0)) {
		xpr = 0.0;

		xpr = Math.floor(left + (xpr-xmin)*xscale) + 0.5;

		myline = contdoc.createElementNS("http://www.w3.org/2000/svg", "svg:line");
		myline.setAttribute("class", "zero");
		myline.setAttribute("x1", "" + xpr);
		myline.setAttribute("y1", "" + (height-(bottom-7.5)));
		myline.setAttribute("x2", "" + xpr);
		myline.setAttribute("y2", "" + (top-15));
		axes.appendChild(myline);
	};

	mypath = contdoc.createElementNS("http://www.w3.org/2000/svg", "svg:path");
	mypath.setAttribute("class", "axis");
	mypath.setAttribute("stroke", "black");
	mypath.setAttribute("d", "M " + left + "," + (height-(bottom-7.5)) + " L " + (width-right+20) + "," + (height-(bottom-7.5)));
	axes.appendChild(mypath);

	mypath = contdoc.createElementNS("http://www.w3.org/2000/svg", "svg:path");
	mypath.setAttribute("d", "M " + (width-right+30) + "," + (height-(bottom-7.5)) + " L " + (width-right+15) + "," + (height-(bottom-4.5)) + " L " + (width-right+15) + "," + (height-(bottom-10.5)));
	axes.appendChild(mypath);

	// - label
	mytext = contdoc.createElementNS("http://www.w3.org/2000/svg", "svg:text");
	mytext.setAttribute("class", "unit");
	mytext.setAttribute("text-anchor", "middle");
	mytext.setAttribute("x", "" + (left+(width-left-right)/2));
	mytext.setAttribute("y", "" + (height-(bottom-40)));
	mytext.appendChild(contdoc.createTextNode(xlabel));
	axes.appendChild(mytext);

	// - ticks, annot
	dtick = (xmax-xmin)/(xNtick-1);
	on = true;

	ypr = (height-(bottom-7.5));

	for (var i = 0; i < xNtick; i++) {
		xpr = xmin + i*dtick;
		xpr = Math.floor(left + (xpr-xmin)*xscale) + 0.5;

		myline = contdoc.createElementNS("http://www.w3.org/2000/svg", "svg:line");
		myline.setAttribute("class", "tick");
		myline.setAttribute("x1", "" + xpr);
		myline.setAttribute("y1", "" + (ypr-5));
		myline.setAttribute("x2", "" + xpr);
		myline.setAttribute("y2", "" + (ypr+5));
		axes.appendChild(myline);

		if (on) {
			mytext = contdoc.createElementNS("http://www.w3.org/2000/svg", "svg:text");
			mytext.setAttribute("class", "annot");
			mytext.setAttribute("text-anchor", "middle");
			mytext.setAttribute("x", "" + xpr);
			mytext.setAttribute("y", "" + (ypr+16));
			mytext.appendChild(contdoc.createTextNode("" + (xmin + i*dtick).toPrecision(4)));
			axes.appendChild(mytext);
		};

		on = !on;
	};

	// -- y(1)-axis

	// - line and arrow
	ypr = ymin;
	ypr = Math.floor(height - bottom) + 0.5;

	myline = contdoc.createElementNS("http://www.w3.org/2000/svg", "svg:line");
	myline.setAttribute("class", "zero");
	myline.setAttribute("x1", "" + (left-7.5));
	myline.setAttribute("y1", "" + ypr);
	myline.setAttribute("x2", "" + (width-right+15));
	myline.setAttribute("y2", "" + ypr);
	axes.appendChild(myline);

	ypr = ymax;
	ypr = Math.floor(height - ((ypr-ymin)*yscale+bottom)) + 0.5;

	myline = contdoc.createElementNS("http://www.w3.org/2000/svg", "svg:line");
	myline.setAttribute("class", "zero");
	myline.setAttribute("x1", "" + (left-7.5));
	myline.setAttribute("y1", "" + ypr);
	myline.setAttribute("x2", "" + (width-right+15));
	myline.setAttribute("y2", "" + ypr);
	axes.appendChild(myline);

	if ((ymin < 0.0) && (ymax > 0.0)) {
		ypr = 0.0;
		ypr = Math.floor(height - ((ypr-ymin)*yscale+bottom)) + 0.5;

		myline = contdoc.createElementNS("http://www.w3.org/2000/svg", "svg:line");
		myline.setAttribute("class", "zero");
		myline.setAttribute("x1", "" + (left-7.5));
		myline.setAttribute("y1", "" + ypr);
		myline.setAttribute("x2", "" + (width-right+15));
		myline.setAttribute("y2", "" + ypr);
		axes.appendChild(myline);

	};

	mypath = contdoc.createElementNS("http://www.w3.org/2000/svg", "svg:path");
	mypath.setAttribute("class", "axis");
	mypath.setAttribute("stroke", "black");
	mypath.setAttribute("d", "M " + (left-7.5) + "," + (height-bottom) + " L " + (left-7.5) + "," + (top-20));
	axes.appendChild(mypath);

	mypath = contdoc.createElementNS("http://www.w3.org/2000/svg", "svg:path");
	mypath.setAttribute("d", "M " + (left-7.5) + "," + (top-30) + " L " + (left-10.5) + "," + (top-15) + " L " + (left-4.5) + "," + (top-15));
	axes.appendChild(mypath);

	// - label
	mytext = contdoc.createElementNS("http://www.w3.org/2000/svg", "svg:text");
	mytext.setAttribute("class", "unit");
	mytext.setAttribute("text-anchor", "middle");
	mytext.setAttribute("x", "0");
	mytext.setAttribute("y", "0");
	mytext.setAttribute("transform", "translate(" + (left-40) + "," + (top+(height-top-bottom)/2) + ") rotate(-90)");
	mytext.appendChild(contdoc.createTextNode(ylabel));
	axes.appendChild(mytext);

	// - ticks, annot
	dtick = (ymax-ymin)/(yNtick-1);
	on = true;

	xpr = left-7.5;

	for (var i = 0; i < yNtick; i++) {
		ypr = ymin + i*dtick;
		ypr = Math.floor(height - ((ypr-ymin)*yscale+bottom)) + 0.5;

		myline = contdoc.createElementNS("http://www.w3.org/2000/svg", "svg:line");
		myline.setAttribute("class", "tick");
		myline.setAttribute("x1", "" + (xpr-5));
		myline.setAttribute("y1", "" + ypr);
		myline.setAttribute("x2", "" + (xpr+5));
		myline.setAttribute("y2", "" + ypr);
		axes.appendChild(myline);

		if (on) {
			mytext = contdoc.createElementNS("http://www.w3.org/2000/svg", "svg:text");
			mytext.setAttribute("class", "annot");
			mytext.setAttribute("text-anchor", "end");
			mytext.setAttribute("x", "" + (xpr-8));
			mytext.setAttribute("y", "" + (ypr+4));
			mytext.appendChild(contdoc.createTextNode("" + (ymin + i*dtick).toPrecision(4)));
			axes.appendChild(mytext);
		};

		on = !on;
	};

	// -- xy data
	xydata = contdoc.getElementById("xydata");

	clearElem(xydata);

	if (xs.length > 0) {
		for (var i = 0; i < yss.length; i++) {
			if (yss[i] == "") continue;
			if (!getNode(srcdoc, "//frdp:" + yss[i])) continue;

			ys = null;

			if (ytype == "i") ys = parseIntvec(getNode(srcdoc, "//frdp:" + yss[i]).textContent);
			else if (ytype == "f") ys = parseFloatvec(getNode(srcdoc, "//frdp:" + yss[i]).textContent);
			else if (ytype == "d") ys = parseDoublevec(getNode(srcdoc, "//frdp:" + yss[i]).textContent);

			if (!ys) continue;

			if (firstys) firstys.push(ys[0]);

		/*
		// circles, useful for non-sequential data in x
			for (var j = 0; j < ys.length; j++) {
				xpr = xs[j];
				if (xDiffNotAbs) xpr = xpr - xs[xs.length-1];

				xpr = left + (xpr-xmin)*xscale;

				ypr = ys[j];

				ypr = height - ((ypr-ymin)*yscale+bottom);

				if ((xpr >= (left-1)) && (xpr <= (width-right+1)) && (ypr >= (top-1)) && (ypr <= (height-bottom+1))) {
					mypath = contdoc.createElementNS("http://www.w3.org/2000/svg", "svg:circle");
					mypath.setAttribute("cx", "" + xpr);
					mypath.setAttribute("cy", "" + ypr);
					mypath.setAttribute("r", "2");
					mypath.setAttribute("stroke-width", "0");
					mypath.setAttribute("fill", "red");

					xydata.appendChild(mypath);
				};
			};
			*/

			mypath = contdoc.createElementNS("http://www.w3.org/2000/svg", "svg:path");
			mypath.setAttribute("class", "l");
			
			stroke = "gray";
			if (i == 0) stroke = "blue";
			else if (i == 1) stroke = "red";
			else if (i == 2) stroke = "limegreen";
			else if (i == 3) stroke = "orange";
			else if (i == 4) stroke = "cyan";
			else if (i == 5) stroke = "magenta";
			else if (i == 6) stroke = "yellow";
			else if (i == 7) stroke = "indigo";

			mypath.setAttribute("stroke", stroke);

			d = "";

			first = true;

			for (var j = 0; j < ys.length; j++) {
				xpr = xs[j];
				if (xDiffNotAbs) xpr = xpr - xs[xs.length-1];

				xpr = left + (xpr-xmin)*xscale;

				ypr = ys[j];

				ypr = height - ((ypr-ymin)*yscale+bottom);

				if ((xpr >= (left-1)) && (xpr <= (width-right+1)) && (ypr >= (top-1)) && (ypr <= (height-bottom+1))) {
					if (first) {
						d = "M ";
						first = false;
					} else d += " L ";

					d += "" + xpr + "," + ypr;
				};
			};
			mypath.setAttribute("d", d);
			
			xydata.appendChild(mypath);
		};
	};
};
