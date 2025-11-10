<template>
	<v-container v-if="initdone">
		<h1 class="text-5 my-3" style="text-align:center">Preferences</h1>
		<PnlWzskPrfDaemon
			v-on:request="handleRequest"
			ref="PnlWzskPrfDaemon"
			:scrJref=statshr.scrJrefDaemon
		/>
		<PnlWzskPrfGlobal
			v-on:request="handleRequest"
			ref="PnlWzskPrfGlobal"
			:scrJref=statshr.scrJrefGlobal
		/>
		<PnlWzskPrfAcqCorner
			v-on:request="handleRequest"
			ref="PnlWzskPrfAcqCorner"
			:scrJref=statshr.scrJrefAcqCorner
		/>
		<PnlWzskPrfAcqPreview
			v-on:request="handleRequest"
			ref="PnlWzskPrfAcqPreview"
			:scrJref=statshr.scrJrefAcqPreview
		/>
		<PnlWzskPrfAcqTrace
			v-on:request="handleRequest"
			ref="PnlWzskPrfAcqTrace"
			:scrJref=statshr.scrJrefAcqTrace
		/>
		<PnlWzskPrfActLaser
			v-on:request="handleRequest"
			ref="PnlWzskPrfActLaser"
			:scrJref=statshr.scrJrefActLaser
		/>
		<PnlWzskPrfActVistorot
			v-on:request="handleRequest"
			ref="PnlWzskPrfActVistorot"
			:scrJref=statshr.scrJrefActVistorot
		/>
		<PnlWzskPrfSrcDcvsp
			v-on:request="handleRequest"
			ref="PnlWzskPrfSrcDcvsp"
			:scrJref=statshr.scrJrefSrcDcvsp
		/>
		<PnlWzskPrfSrcSysinfo
			v-on:request="handleRequest"
			ref="PnlWzskPrfSrcSysinfo"
			:scrJref=statshr.scrJrefSrcSysinfo
		/>
		<PnlWzskPrfSrcTivsp
			v-on:request="handleRequest"
			ref="PnlWzskPrfSrcTivsp"
			:scrJref=statshr.scrJrefSrcTivsp
		/>
		<PnlWzskPrfSrcZuvsp
			v-on:request="handleRequest"
			ref="PnlWzskPrfSrcZuvsp"
			:scrJref=statshr.scrJrefSrcZuvsp
		/>
	</v-container>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	*/
	import PnlWzskPrfDaemon from './PnlWzskPrfDaemon';
	import PnlWzskPrfGlobal from './PnlWzskPrfGlobal';
	import PnlWzskPrfAcqCorner from './PnlWzskPrfAcqCorner';
	import PnlWzskPrfAcqPreview from './PnlWzskPrfAcqPreview';
	import PnlWzskPrfAcqTrace from './PnlWzskPrfAcqTrace';
	import PnlWzskPrfActLaser from './PnlWzskPrfActLaser';
	import PnlWzskPrfActVistorot from './PnlWzskPrfActVistorot';
	import PnlWzskPrfSrcDcvsp from './PnlWzskPrfSrcDcvsp';
	import PnlWzskPrfSrcSysinfo from './PnlWzskPrfSrcSysinfo';
	import PnlWzskPrfSrcTivsp from './PnlWzskPrfSrcTivsp';
	import PnlWzskPrfSrcZuvsp from './PnlWzskPrfSrcZuvsp';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWzskPrf',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWzskPrfDaemon,
			PnlWzskPrfGlobal,
			PnlWzskPrfAcqCorner,
			PnlWzskPrfAcqPreview,
			PnlWzskPrfAcqTrace,
			PnlWzskPrfActLaser,
			PnlWzskPrfActVistorot,
			PnlWzskPrfSrcDcvsp,
			PnlWzskPrfSrcSysinfo,
			PnlWzskPrfSrcTivsp,
			PnlWzskPrfSrcZuvsp
			/*
			*/
		},

		mounted() {
			//console.log("CrdWzskPrf.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWzskInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContInfWzskPrf) this.continf = dpcheng.ContInfWzskPrf;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWzskPrf) this.statapp = dpcheng.StatAppWzskPrf;
				if (dpcheng.StatShrWzskPrf) this.statshr = dpcheng.StatShrWzskPrf;
				if (dpcheng.TagWzskPrf) {
					Wzsk.unescapeBlock(dpcheng.TagWzskPrf);
					this.tag = dpcheng.TagWzskPrf;
				}
				/*
				*/
			},

			handleCrdopen: function(obj) {
				this.$emit("crdopen", obj)
			},

			handleRequest: function(obj) {
				this.$emit("request", obj)
			},

			handleReply: function(obj) {
				if (obj.scrJref == this.scrJref) {
					if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);

				} else if (this.initdone) {
					/*
					*/
					if (obj.scrJref == this.statshr.scrJrefDaemon) this.$refs.PnlWzskPrfDaemon.handleReply(obj);
					else if (obj.scrJref == this.statshr.scrJrefGlobal) this.$refs.PnlWzskPrfGlobal.handleReply(obj);
					else if (obj.scrJref == this.statshr.scrJrefAcqCorner) this.$refs.PnlWzskPrfAcqCorner.handleReply(obj);
					else if (obj.scrJref == this.statshr.scrJrefAcqPreview) this.$refs.PnlWzskPrfAcqPreview.handleReply(obj);
					else if (obj.scrJref == this.statshr.scrJrefAcqTrace) this.$refs.PnlWzskPrfAcqTrace.handleReply(obj);
					else if (obj.scrJref == this.statshr.scrJrefActLaser) this.$refs.PnlWzskPrfActLaser.handleReply(obj);
					else if (obj.scrJref == this.statshr.scrJrefActVistorot) this.$refs.PnlWzskPrfActVistorot.handleReply(obj);
					else if (obj.scrJref == this.statshr.scrJrefSrcDcvsp) this.$refs.PnlWzskPrfSrcDcvsp.handleReply(obj);
					else if (obj.scrJref == this.statshr.scrJrefSrcSysinfo) this.$refs.PnlWzskPrfSrcSysinfo.handleReply(obj);
					else if (obj.scrJref == this.statshr.scrJrefSrcTivsp) this.$refs.PnlWzskPrfSrcTivsp.handleReply(obj);
					else if (obj.scrJref == this.statshr.scrJrefSrcZuvsp) this.$refs.PnlWzskPrfSrcZuvsp.handleReply(obj);
					else console.log("got a '" + obj.srefIxWzskVDpch + "' from job with scrJref " + obj.dpcheng.scrJref);
					/*
					*/
				}
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWzskVDpch == "DpchEngWzskPrfData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefDaemon) {
						this.$refs.PnlWzskPrfDaemon.handleUpdate(obj);
						processed = true;
					} else if (obj.dpcheng.scrJref == this.statshr.scrJrefGlobal) {
						this.$refs.PnlWzskPrfGlobal.handleUpdate(obj);
						processed = true;
					} else if (obj.dpcheng.scrJref == this.statshr.scrJrefAcqCorner) {
						this.$refs.PnlWzskPrfAcqCorner.handleUpdate(obj);
						processed = true;
					} else if (obj.dpcheng.scrJref == this.statshr.scrJrefAcqPreview) {
						this.$refs.PnlWzskPrfAcqPreview.handleUpdate(obj);
						processed = true;
					} else if (obj.dpcheng.scrJref == this.statshr.scrJrefAcqTrace) {
						this.$refs.PnlWzskPrfAcqTrace.handleUpdate(obj);
						processed = true;
					} else if (obj.dpcheng.scrJref == this.statshr.scrJrefActLaser) {
						this.$refs.PnlWzskPrfActLaser.handleUpdate(obj);
						processed = true;
					} else if (obj.dpcheng.scrJref == this.statshr.scrJrefActVistorot) {
						this.$refs.PnlWzskPrfActVistorot.handleUpdate(obj);
						processed = true;
					} else if (obj.dpcheng.scrJref == this.statshr.scrJrefSrcDcvsp) {
						this.$refs.PnlWzskPrfSrcDcvsp.handleUpdate(obj);
						processed = true;
					} else if (obj.dpcheng.scrJref == this.statshr.scrJrefSrcSysinfo) {
						this.$refs.PnlWzskPrfSrcSysinfo.handleUpdate(obj);
						processed = true;
					} else if (obj.dpcheng.scrJref == this.statshr.scrJrefSrcTivsp) {
						this.$refs.PnlWzskPrfSrcTivsp.handleUpdate(obj);
						processed = true;
					} else if (obj.dpcheng.scrJref == this.statshr.scrJrefSrcZuvsp) {
						this.$refs.PnlWzskPrfSrcZuvsp.handleUpdate(obj);
						processed = true;
					}
					/*
					*/
				}

				//if (!processed) console.log("got a '" + obj.srefIxWzskVDpch + "' from job with scrJref " + obj.dpcheng.scrJref);

				return processed
			},
		},

		data: () => ({
			initdone: false,

			/*
			*/
			continf: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			tag: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
